//
//  timer.cpp
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/22.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "timer.h"

Uint32 Timer::now, Timer::wit, Timer::lev;

void Timer::Init() {
    Timer::now = 0;
    Timer::wit = 0;
    Timer::lev = 0;
}

void Timer::Frames() {
    Timer::now = SDL_GetTicks();
    Timer::wit = Timer::now - Timer::lev;
    if (Timer::wit < 16)
        SDL_Delay(16 - Timer::wit);
    Timer::lev = SDL_GetTicks();
}