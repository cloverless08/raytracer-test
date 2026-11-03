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
    m_camera.SetAspectRatio(4.0 / 3.0);

    m_camera.UpdateCamera();


    // construct test sphere
    m_objectList.push_back(std::make_shared<raytrace::ObjSphere>(raytrace::ObjSphere()));

    // construct a test light source
    m_lightList.push_back(std::make_shared<raytrace::PointLight>(raytrace::PointLight())); // calls default constructor
    // modify initial location and color
    std::vector<double> inputLocation;
    //std::vector<double> inputColor;

    for (int i = 0; i < 3; ++i) {
        double input;
        std::cout << "Coordinate " << i << ": ";
        std::cin >> input;
        input = static_cast<double>(input);
        inputLocation.push_back(input);
    }

    //m_lightList.at(0) -> m_location = qbVector<double> {std::vector<double>{5.0, -10.0, -5.0}};
    m_lightList.at(0) -> m_location = qbVector<double> {inputLocation};
    m_lightList.at(0) -> m_color = qbVector<double> {std::vector<double>{255.0, 255.0, 255.0}};
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
    double maxDistance = 0.0;

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


            // test for intersections with all objects in scene
            for (auto currentObject : m_objectList) { // loop through all objects in object list and return reference to that in currentObject
                bool validIntersection = currentObject -> TestIntersection(camRay, intersectionPoint, localNorm, localColor);

                if (validIntersection) {
                    // compute intensity of illumination
                    double intensity;
                    qbVector<double> color {3};
                    bool validIllumination = false;
                    for (auto currentLight : m_lightList) { // currently hard-coded to only deal with one light source
                        validIllumination = currentLight -> ComputeIllumination(intersectionPoint,
                            localNorm,
                            m_objectList,
                            currentObject,
                            color,
                            intensity);
                    }

                    // compute distance between camera and int
                    double dist = (intersectionPoint - camRay.m_point1).norm();
                    if (dist > maxDistance) { // check mainly for debugging
                        maxDistance = dist;
                    }

                    if (dist < minDistance) { // check mainly for debugging
                        minDistance = dist;
                    }

                    //outputImage.SetPixel(x, y, 255.0 - ((dist - 9.0) / 0.94605) * 255.0, 0.0, 0.0);
                    if (validIllumination) {
                        outputImage.SetPixel(x, y, 255.0 * intensity, 0.0, 0.0);
                    } else {
                        outputImage.SetPixel(x, y, 0.0, 0.0, 0.0); // sets black if theres no illumination
                    }


                    std::cout << "true" << std::endl;
                } else {
                    outputImage.SetPixel(x, y, 0.0, 0.0, 0.0);
                    std::cout << "false" << std::endl;
                }

                std::cout << "done" << std::endl;
            }
        }
    }

    std::cout << "Minimum Distance: " << minDistance << std::endl;
    std::cout << "Maximum Distance: " << maxDistance << std::endl;
    return true;
}
