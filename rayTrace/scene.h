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
#include <memory>

#include "image.h"
#include "camera.h"
#include "objects/objsphere.h"
#include "objects/pointlight.h"

namespace Raytrace {
    class Scene {
    public:
        // default constructor
        Scene(); // no destrucotr needed

        // redner function
        bool Render(raytrace::Image &outputImage);

    private:
        raytrace::Camera m_camera;

        // list of objects in scene
        std::vector<std::shared_ptr<raytrace::ObjectBase>> m_objectList;

        // list of lights in scene
        std::vector<std::shared_ptr<raytrace::LightBase>> m_lightList;

        // unit sphere on origin for testing
        raytrace::ObjSphere m_testSphere;

    };
}
