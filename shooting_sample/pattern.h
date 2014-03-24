//
//  pattern.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/27.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_pattern_h
#define shooting_sample_pattern_h

#include <SDL2/SDL.h>

class Enemy_Act {
public:
    int a;
private:
    enum type {MOVE=0, SHOT=1};
    int x, y;
    Ball ball;
};


#endif
