//
//  ball.cpp
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/24.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ball.h"

Ball::Ball() {
    flag = false;
}

void Ball::Init(SDL_Texture* a_img, SDL_Rect a_pos, int a_x_move, int a_y_move) {
    img = a_img;
    pos = a_pos;
    x_move = a_x_move;
    y_move = a_y_move;
    flag = true;
}

void Ball::Move() {
    pos.x += x_move;
    pos.y += y_move;
    if (pos.x < 0 or pos.x > Window::Box().w or pos.y < 0 or pos.y > Window::Box().h)
        flag = false;
}

SDL_Texture* Ball::Get_Img() {
    return img;
}

SDL_Rect Ball::Get_Pos() {
    return pos;
}

bool Ball::Get_Flag() {
    return flag;
}