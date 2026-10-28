//
// Project: raytracer-test
// File: CApp.h
// Purpose: Public interface for the top-level application controller.
// Author: cdemin
// Updated: 2026-10-28
//

#pragma once

#include "SDL2/SDL.h"
#include "./rayTrace/image.h"
#include "./rayTrace/scene.h"

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
    raytrace::Image m_image;

    // declare an instance of the Scene class
    Raytrace::Scene m_scene;

    // SDL2 stuff basically
    bool running;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
};
