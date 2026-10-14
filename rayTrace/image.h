//
// Created by cdemin on 10/14/26.
//

#pragma once

#include <string>
#include <vector>
#include "SDL2/SDL.h"

class Image {
    // default constructor
    Image();

    // default destrucor
    ~Image();

    void Init(const int sizeX, const int sizeY, SDL_Renderer *pRenderer);

    // function to set color of a pixel
    void SetPixel(const int x, const int y, const double red, const double green, const double blue); // i completely disagree with this implementation and will be doing something different in the sim

};