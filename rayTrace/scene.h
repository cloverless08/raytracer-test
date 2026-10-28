//
// Project: raytracer-test
// File: rayTrace/scene.h
// Purpose: Declares the scene graph and render pipeline interface.
// Author: cdemin
// Updated: 2026-10-28
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
