//
//  resources.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/03/03.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_resources_h
#define shooting_sample_resources_h

#include <SDL2/SDL.h>

class Resources {
public:
    static void Init();
    static SDL_Texture* bg_imgs();
    static SDL_Texture* chara_imgs();
    static SDL_Texture* ball_imgs();
private:
    static std::string *bg_img_filename_, *chara_img_filename_, *ball_img_filename_;
    static SDL_Texture *bg_imgs_, *chara_imgs_, *ball_imgs_;
};

#endif
