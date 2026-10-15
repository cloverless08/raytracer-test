//
// Created by cdemin on 10/13/26.
//

#pragma once

#include "SDL2/SDL.h"
#include "./rayTrace/image.h"

class CApp {
public:
    CApp();

    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event *event);
    void OnLoop();
    void OnRender();
    void OnExit();

private:
    // declare in instance of the Image class
    Image m_image;

    // SDL2 stuff basically
    bool running;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
};