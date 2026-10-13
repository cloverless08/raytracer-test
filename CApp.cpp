//
// Created by cdemin on 10/13/26.
//

#include "CApp.h"

constexpr int WIDTH = 480;
constexpr int HEIGHT = 640;

// definte default constructor
CApp::CApp() {
    running = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
        return false;
    }

    pWindow = SDL_CreateWindow(
        "Ray Tracing Test",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
        );

    if (pWindow != false) {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    }
}
