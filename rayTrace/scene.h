//
// Created by cdemin on 10/18/26.
//

#pragma once

#include <vector>
#include <SDL2/SDL.h>

#include "image.h"

namespace Raytrace {
    class Scene {
    public:
        // default constructor
        Scene(); // no destrucotr needed

        // redner function
        bool Render(raytrace::Image &outputImage);

    private:
        // future ref
    };
}