//
// Created by cdemin on 10/23/26.
//

#pragma once

#include "./qbLinearAlgebra/qbVector.h"
#include "ray.h"

namespace rayTrace {
    class Camera {
    public:
        // default constructor
        Camera();

        // camera paramter functions
        void SetPosition(const qbVector<double> &newPosition);
        void SetLookAt(const qbVector<double> &newLookAt);
        void SetUp(const qbVector<double> &upVector);
        void SetLength(double newLength); // distance from virtual screen


    };
}