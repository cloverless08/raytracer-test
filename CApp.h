//
// Created by cdemin on 10/13/26.
//

#pragma once

#include "SDL2/SDL.h"

class CApp {
    public:
    CApp();

    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event *event);
};