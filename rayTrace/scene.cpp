//
// Project: raytracer-test
// File: rayTrace/scene.cpp
// Purpose: Implements the scene render loop and frame generation.
// Author: cdemin
// Updated: 2026-10-28
//

#include "scene.h"
#include <SDL2/SDL.h>
#include "image.h"

// constructor
Raytrace::Scene::Scene() {
    // configure camera
    m_camera.SetPosition(qbVector<double>{std::vector<double>{0.0, -10.0, 0.0}} );
    m_camera.SetLookAt(qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}}); // look at origin
    m_camera.SetUp(qbVector<double>{std::vector<double>{0.0, 0.0, 1.0}});

    m_camera.SetHorizontalSize(0.25);
    m_camera.SetAspectRatio(16.0 / 9.0);

    m_camera.UpdateCamera();
}

// render func
bool Raytrace::Scene::Render(raytrace::Image &outputImage) {
    // get dimensions of output image
    int sizeX = outputImage.GetSizeX();
    int sizeY = outputImage.GetSizeY();



    return false;
}
