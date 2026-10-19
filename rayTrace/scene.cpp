//
// Created by cdemin on 10/18/26.
//

#include "scene.h"
#include <SDL2/SDL.h>

// constructor
RayTrace::Scene::Scene() {

}

// render func
bool RayTrace::Scene::Render(Image &outputImage) {
    // get dimensions of output image
    int sizeX = outputImage.GetXSize();
    int sizeY = outputImage.GetYSize();

    // creates color variation
    for (int x = 0; x < sizeX; ++x) {
        for (int y = 0; y < sizeY; ++y) {
            double red = (static_cast<double>(x)/static_cast<double>(sizeX)) * 255.0;
            double green = (static_cast<double>(y)/static_cast<double>(sizeY)) * 225.0;
            outputImage.SetPixel(x, y, red, green, 0.0);
        }
    }

    return false;
}
