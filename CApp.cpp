//
// Project: raytracer-test
// File: CApp.cpp
// Purpose: Implements the application shell, SDL setup, and event loop.
// Author: cdemin
// Updated: 2026-10-28
//

#include "CApp.h"
#include "SDL2/SDL.h"

#include "./rayTrace/qbLinearAlgebra/qbVector.h"

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

    // initialize camera
    raytrace::Camera testCamera;
        testCamera.SetPosition(qbVector<double>(std::vector<double>{0.0, 0.0, 0.0}));
        testCamera.SetLookAt(qbVector<double>(std::vector<double>{0.0, 2.0, 0.0})); // looks 2 units away in the y direction
        testCamera.SetUp(qbVector<double>(std::vector<double>{0.0, 0.0, 1.0}));
        testCamera.SetLength(1.0);
        testCamera.SetHorizontalSize(1.0);
        testCamera.SetAspectRatio(1.0);

        testCamera.UpdateCamera();


        // get scren center and UV coordinate vectors, then display
        auto screenCenter = testCamera.GetScreenCenter();
        auto screenU = testCamera.GetU();
        auto screenV = testCamera.GetV();

        std::cout << "Camera Screen Center: " << std::endl;
        PrintVector(screenCenter);
        std::cout << "\nCamera U Vector:" << std::endl;
        PrintVector(screenU);
        std::cout << "\nCamera V Vector:" << std::endl;
        PrintVector(screenV);



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

    m_scene.Render(m_image); // render the scene

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


// private function definitions
//----------------------------------

void CApp::PrintVector(const qbVector<double> &inputvec) {
    int numRows = inputvec.GetNumDims();
    for (int i = 0; i < numRows; ++i) {
        std::cout << std::fixed << std::setprecision(3) << inputvec.GetElement(i) << std::endl;
    }
}
