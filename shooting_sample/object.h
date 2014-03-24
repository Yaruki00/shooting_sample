//
//  object.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/03/01.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_object_h
#define shooting_sample_object_h

#include <SDL2/SDL.h>
#include "act.h"
#include "window.h"

class Object {
public:
    Object(SDL_Texture* img, Act *pattern);
    void Init(SDL_Rect pos, int start_frame);
    Object *Act(int frame);
    SDL_Texture *img();
    SDL_Rect pos();
    bool flag();
private:
    SDL_Texture *img_, *ch_img_;
    struct Act *pattern_;
    SDL_Rect pos_;
    bool flag_;
    int start_frame_;
    int (*move_x)(int), (*move_y)(int), (*shot_x)(int), (*shot_y)(int);
};

#endif
