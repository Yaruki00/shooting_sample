//
//  enemy.cpp
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/26.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "enemy.h"

Enemy::Enemy() {
    flag = false;
}

void Enemy::Init(SDL_Texture* a_img, SDL_Rect a_pos, EnemyAct* a_pattern) {
    img = a_img;
    pos = a_pos;
    pattern = a_pattern;
    flag = true;
}

Ball *Enemy::Act() {
    Ball *ball;
    if (pattern->type == 0) {
        pos.x += pattern->move_x;
        pos.y += pattern->move_y;
        if (pos.x < 0 or pos.x > Window::Box().w or pos.y < 0 or pos.y > Window::Box().h)
            flag = false;
    }
    ball = pattern->ball;
    pattern = pattern->next;
    return ball;
}

SDL_Texture* Enemy::Get_Img() {
    return img;
}

SDL_Rect Enemy::Get_Pos() {
    return pos;
}

bool Enemy::Get_Flag() {
    return flag;
}