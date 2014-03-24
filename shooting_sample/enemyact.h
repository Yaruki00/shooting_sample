//
//  enemyact.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/28.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_enemyact_h
#define shooting_sample_enemyact_h

#include "ball.h"

enum Type {MOVE=0, SHOT=1};
struct EnemyAct {
    Type type;
    int move_x, move_y;
    Ball* ball;
    EnemyAct* next;
};

#endif
