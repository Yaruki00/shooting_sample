//
//  new_main.cpp
//  game_sample
//
//  Created by 裕太 川辺 on 14/02/21.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "window.h"
#include "timer.h"
#include "ball.h"
#include "enemy.h"
#include "enemyact.h"

#define MY_BALLS_MAX 1000
#define ENE_BALLS_MAX 1000
#define ENE_MAX 100

int main(int argc, const char * argv[]) {
    //Start our window
    SDL_Rect window_pos = { 0, 0, 800, 600 };
    try {
        Window::Init("shooooooting", window_pos);
    }
    catch (const std::runtime_error &e){
        std::cout << e.what() << std::endl;
        Window::Quit();
        return -1;
    }
    //Init Timer
    Timer::Init();
    //Load up an image and some text
    // TODO: リソースとしてまとめる
    SDL_Texture *img, *me, *enemy_img, *ball, *msg1, *msg2, *msg3;
    try {
        //Load the image
        std::string imgFile = "/Users/Yuta/Pictures/rect.png";
        img = Window::LoadImage(imgFile);
        imgFile = "/Users/Yuta/Pictures/me.png";
        me = Window::LoadImage(imgFile);
        imgFile = "/Users/Yuta/Pictures/enemy.png";
        enemy_img = Window::LoadImage(imgFile);
        imgFile = "/Users/Yuta/Pictures/ball.png";
        ball = Window::LoadImage(imgFile);
        //Load the font and message
        std::string fontFile = "/Users/Yuta/hanazono-20131208/HanaMinA.ttf";
        std::string text = "rotation!";
        SDL_Color color = { 255, 255, 255 };
        msg1 = Window::RenderText(text, fontFile, color, 25);
        text = "TITLE";
        color.b = 0;
        color.r = 0;
        msg2 = Window::RenderText(text, fontFile, color, 60);
        text = "GAMEOVER";
        color.g = 0;
        color.b = 0;
        color.r = 255;
        msg3 = Window::RenderText(text, fontFile, color, 60);
        
    }
    catch (const std::runtime_error &e){
        //Catch error and crash
        std::cout << e.what() << std::endl;
        Window::Quit();
        return -1;
    }
    //Set a position to draw it with
    SDL_Rect me_pos = { Window::Box().w / 2 - 30 / 2, 550, 30, 30 };
    SDL_Rect ene_pos = { Window::Box().w / 2 - 30 / 2, 50, 30, 30 };
    SDL_Rect bgimg_pos = {0, 0, Window::Box().w, Window::Box().h};
    SDL_Rect ene1_pos = { 10, 0, 30, 30 };
    SDL_Rect ene2_pos = { 20, 0, 30, 30 };
    int move_size = 10;
    //The angle to draw at, so we can play with it
    int angle = 0;
    int cnt;
    //balls
    Ball *my_balls, *ene_balls, *new_ball = new Ball;
    //enemies
    EnemyAct move_down_inf = {MOVE, 0, 3, NULL, &move_down_inf};
    EnemyAct shot_to_me = {SHOT, NULL, NULL, new_ball, &move_down_inf};
    EnemyAct move_down_thd = {MOVE, 0, 3, NULL, &shot_to_me};
    EnemyAct move_down_snd = {MOVE, 0, 3, NULL, &move_down_thd};
    EnemyAct move_down_fst = {MOVE, 0, 3, NULL, &move_down_snd};
    Enemy *enemy1 = new Enemy, *enemy2 = new Enemy, *ene_list;
    //gamestatus
    enum Game_Status {TITLE=0, GAME=1, OVER=2};
    Game_Status game_status = TITLE;
    //frame counter
    int f_cnt;
    //event loop
    SDL_Event e;
    bool bExit = false;
    while (!bExit){
        Timer::Frames();
        // title
        if (game_status == TITLE) {
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT) // ウィンドウを閉じる
                    bExit = true;
                if (e.type == SDL_KEYDOWN)
                    switch (e.key.keysym.sym) {
                        case SDLK_RETURN:
                            game_status = GAME;
                            me_pos = (SDL_Rect){ Window::Box().w / 2 - 30 / 2, 550, 30, 30 };
                            ene_pos = (SDL_Rect){ Window::Box().w / 2 - 30 / 2, 50, 30, 30 };
                            ene_list = new Enemy[ENE_MAX];
                            my_balls = new Ball[MY_BALLS_MAX];
                            ene_balls = new Ball[ENE_BALLS_MAX];
                            f_cnt = 0;
                            break;
                        case SDLK_ESCAPE:
                            bExit = true;
                            break;
                    }
            }
            //RENDERING
            Window::Clear();
            SDL_Rect tmp_pos = {Window::Box().w / 2 - 400 / 2,
                Window::Box().h / 2 - 300 / 2 - 100, 400, 300};
            Window::Draw(msg2, tmp_pos, NULL, 0);
            
            Window::Present();
        }
        // game
        else if (game_status == GAME) {
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT) // ウィンドウを閉じる
                    bExit = true;
                if (e.type == SDL_KEYDOWN)
                    switch (e.key.keysym.sym) {
                        case SDLK_UP:
                            if (me_pos.y < move_size)
                                me_pos.y = 0;
                            else
                                me_pos.y -= move_size;
                            break;
                        case SDLK_DOWN:
                            if (me_pos.y > window_pos.h - me_pos.h - move_size)
                                me_pos.y = window_pos.h - me_pos.h;
                            else
                                me_pos.y += move_size;
                            break;
                        case SDLK_RIGHT:
                            if (me_pos.x > window_pos.w - me_pos.w - move_size)
                                me_pos.x = window_pos.w - me_pos.w;
                            else
                                me_pos.x += move_size;
                            break;
                        case SDLK_LEFT:
                            if (me_pos.x < move_size)
                                me_pos.x = 0;
                            else
                                me_pos.x -= move_size;
                            break;
                        case SDLK_z:
                            cnt = -5;
                            for (int i=0; i<MY_BALLS_MAX; i++) {
                                if (my_balls[i].Get_Flag() == false) {
                                    my_balls[i].Init(ball, me_pos, cnt, -15);
                                    cnt++;
                                    if (cnt == 6)
                                        break;
                                }
                            }
                            break;
                        case SDLK_RETURN:
                            game_status = OVER;
                            break;
                    }
            }
            //moving
            //old
            for (int i=0; i<MY_BALLS_MAX; i++)
                if (my_balls[i].Get_Flag() == true)
                    my_balls[i].Move();
            for (int i=0; i<ENE_BALLS_MAX; i++)
                if (ene_balls[i].Get_Flag() == true)
                    ene_balls[i].Move();
            if (ene_pos.x + 5 < Window::Box().w)
                ene_pos.x += 5;
            else
                ene_pos.x = ene_pos.x + 0 - Window::Box().w;
            //new
            for (int i=0; i<ENE_MAX; i++)
                if (ene_list[i].Get_Flag() == true) {
                    if (ene_list[i].Act() != NULL) {
                        new_ball->Init(ball, ene_list[i].Get_Pos(), 3, 3);
                        for (int i=0; i<ENE_BALLS_MAX; i++) {
                            if (ene_balls[i].Get_Flag() == false) {
                                ene_balls[i] = *new_ball;
                                break;
                            }
                        }
                    }
                }
            //enemy shot
            /*
            if ((double)rand() / RAND_MAX > 0.95) {
                for (int i=0; i<ENE_BALLS_MAX; i++) {
                    if (ene_balls[i].Get_Flag() == false) {
                        ene_balls[i].Init(ball, ene_pos, 0, 2);
                        break;
                    }
                }
            }*/
            
            //enemy apper
            if (f_cnt % 60 == 0 and f_cnt % 120 != 0) {
                enemy1->Init(enemy_img, ene1_pos, &move_down_fst);
                for (int i=0; i<ENE_MAX; i++)
                    if (ene_list[i].Get_Flag() == false) {
                        ene_list[i] = *enemy1;
                        break;
                    }
            }
            if (f_cnt % 120 == 0) {
                enemy2->Init(enemy_img, ene2_pos, &move_down_fst);
                for (int i=0; i<ENE_MAX; i++)
                    if (ene_list[i].Get_Flag() == false) {
                        ene_list[i] = *enemy2;
                        break;
                    }
            }
            //RENDERING
            Window::Clear();
            
            
            Window::Draw(img, bgimg_pos, NULL, 0);
            
            Window::Draw(me, me_pos, NULL, angle);
            for (int i=0; i<MY_BALLS_MAX; i++) {
                if (my_balls[i].Get_Flag() == true) {
                    SDL_Rect pos = my_balls[i].Get_Pos();
                    if (pos.x > ene_pos.x - ene_pos.w/2 and pos.x < ene_pos.x + ene_pos.w/2 and
                        pos.y > ene_pos.y - ene_pos.h/2 and pos.y < ene_pos.y + ene_pos.h/2)
                        game_status = TITLE;
                    else
                        Window::Draw(my_balls[i].Get_Img(), pos, NULL, 0);
                }
            }
            for (int i=0; i<ENE_BALLS_MAX; i++) {
                if (ene_balls[i].Get_Flag() == true) {
                    SDL_Rect pos = ene_balls[i].Get_Pos();
                    if (pos.x > me_pos.x - me_pos.w/2 and pos.x < me_pos.x + me_pos.w/2 and
                        pos.y > me_pos.y - me_pos.h/2 and pos.y < me_pos.y + me_pos.h/2)
                        game_status = OVER;
                    else
                        Window::Draw(ene_balls[i].Get_Img(), pos, NULL, 0);
                }
            }
            
            Window::Draw(enemy_img, ene_pos, NULL, angle);
            
            for (int i=0; i<ENE_MAX; i++)
                if (ene_list[i].Get_Flag()) {
                    SDL_Rect pos = ene_list[i].Get_Pos();
                    Window::Draw(ene_list[i].Get_Img(), pos, NULL, 0);
                }
            
            Window::Present();
            
            f_cnt++;
            
            
        }
        // gameover
        else if (game_status == OVER) {
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT) // ウィンドウを閉じる
                    bExit = true;
                if (e.type == SDL_KEYDOWN)
                    switch (e.key.keysym.sym) {
                        case SDLK_RETURN:
                            game_status = TITLE;
                            break;
                        case SDLK_ESCAPE:
                            bExit = true;
                            break;
                    }
            }
            //RENDERING
            Window::Clear();
            SDL_Rect tmp_pos = {Window::Box().w / 2 - 400 / 2,
                Window::Box().h / 2 - 300 / 2 - 100, 400, 300};
            Window::Draw(msg3, tmp_pos, NULL, 0);
            
            Window::Present();
        }        
    }
}