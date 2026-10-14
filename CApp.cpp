//
// Created by cdemin on 10/13/26.
//

#include "CApp.h"

constexpr int WIDTH = 480;
constexpr int HEIGHT = 640;

// define default constructor
CApp::CApp() {
    running = true;
    pWindow = nullptr;
    pRenderer = nullptr;
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

    if (pWindow != nullptr) {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    } else {
        return false;
    }
    return true;
}

int CApp::OnExecute() {
    SDL_Event event;

    if (OnInit() == false) {
        return -1;
    }

    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();

    }
}

void CApp::OnEvent(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        running = false;
    }
}

void CApp::OnLoop() {

}

void CApp::OnRender() {
 // set background to white
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
}