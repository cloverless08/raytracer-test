//
// Created by cdemin on 10/13/26.
//

#include "CApp.h"
#include "SDL2/SDL.h"

constexpr int HEIGHT = 480;
constexpr int WIDTH = 640;

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
        "ray freaking tracing freaking test",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
        );

    if (pWindow != nullptr) {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0); // initalize renderer
        m_image.Init(WIDTH, HEIGHT, pRenderer); // initalize image instance

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
//
    return 0;
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
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255); // white is a stupid color tbh
    SDL_RenderClear(pRenderer);

    // display the image
    m_image.Display(WIDTH, HEIGHT);

    SDL_RenderPresent(pRenderer);
}

void CApp::OnExit() {
    //sdl2 cleanup
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = nullptr;

    SDL_Quit();
}
