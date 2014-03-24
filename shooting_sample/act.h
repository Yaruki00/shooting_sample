//
//  act.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/03/01.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_act_h
#define shooting_sample_act_h

enum Type {NONE=0, MOVE=1, SHOT=2, BOTH=3};
struct Act {
    Type type;
    Act* next;
};

#endif
