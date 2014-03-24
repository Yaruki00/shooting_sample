//
//  timer.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/22.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_timer_h
#define shooting_sample_timer_h

#include <SDL2/SDL.h>

class Timer {
public:
    static void Init();
    static void Frames();
private:
    static Uint32 now, wit, lev;
};

#endif
