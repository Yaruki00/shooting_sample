//
//  enemy.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/26.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_enemy_h
#define shooting_sample_enemy_h

#include <SDL2/SDL.h>
#include "window.h"
#include "enemyact.h"

class Enemy {
public:
    Enemy();
    void Init(SDL_Texture* a_img, SDL_Rect a_pos, EnemyAct *a_pattern);
    Ball *Act();
    SDL_Texture *Get_Img();
    SDL_Rect Get_Pos();
    bool Get_Flag();
private:
    SDL_Texture *img;
    SDL_Rect pos;
    EnemyAct *pattern;
    bool flag;
};

#endif
