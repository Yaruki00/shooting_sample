//
//  object.cpp
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/03/01.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "object.h"

Object::Object(SDL_Texture* img, struct Act *pattern) : img_(img), pattern_(pattern) {
    flag_ = false;
}

void Object::Init(SDL_Rect pos, int start_frame) {
    pos_ = pos;
    start_frame_ = start_frame;
    flag_ = true;
    
}

Object *Object::Act(int frame) {
    Object *result=NULL;
    frame -= start_frame_;
    if (pattern_->type == MOVE or pattern_->type == BOTH) {
        pos_.x += move_x(frame);
        pos_.y += move_y(frame);
        if (pos_.x < 0 or pos_.x > Window::Box().w or pos_.y < 0 or pos_.y > Window::Box().h)
            flag_ = false;
    }
    if (pattern_->type == SHOT or pattern_->type == BOTH) {
        //result = new Object;
    }
    pattern_ = pattern_->next;
    return result;
}