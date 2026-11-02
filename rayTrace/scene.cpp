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

    std::cout << "sizeX = " << sizeX << std::endl;
    std::cout << "sizeY = " << sizeY << std::endl;

    // loop over each pixel in image
    raytrace::Ray camRay;
    qbVector<double> intersectionPoint(3);
    qbVector<double> localNorm(3);
    qbVector<double> localColor(3);

    double xFactor = 1.0 / (static_cast<double>(sizeX) / 2.0);
    double yFactor = 1.0 / (static_cast<double>(sizeY) / 2.0);

    double minDistance = 1e6;
    double maxDinstance = 0.0;

    // actually raytrace it all
    for (int x = 0; x < sizeX; ++x) {
        for (int y = 0; y < sizeY; ++y) {

            std::cout << "x = " << x << " y = " << y << std::endl;
            std::cout << "Starting calculation..." << std::endl;

            // normalize x and y coordinate to range from -1 to 1
            double normX = (static_cast<double>(x) * xFactor) - 1.0;
            double normY = (static_cast<double>(y) * yFactor) - 1.0;

            // generate a ray for this pixel
            m_camera.GenerateRay(normX, normY, camRay);

            // test for valid intersection and modify screen
            bool validIntersection = m_testSphere.TestIntersection(camRay, intersectionPoint, localNorm, localColor);

            if (validIntersection) {
                outputImage.SetPixel(x, y, 255.0, 0.0, 0.0);
                std::cout << "true" << std::endl;
            } else {
                outputImage.SetPixel(x, y, 0.0, 0.0, 0.0);
                std::cout << "false" << std::endl;
            }

            std::cout << "done" << std::endl;
        }
    }

    return false;
}
