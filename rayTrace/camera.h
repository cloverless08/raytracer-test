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

        void SetHorizontalSize(double horizontalSize); // defines aspect ratio
        void SetAspectRatio(double aspectRatio);

        // parameter getter functions
        qbvector<double> GetPosition() const;
        qbvector<double> GetLookAt() const;
        qbVector<double> GetUp() const;
        qbVector<double> GetU(); // screen dimensions getter
        qbVector<double> GetV() const; // screen dimension getter
        qbVector<double> GetScreenCenter() const;

        double getLength();
        double getHorizontalSize();
        double getAspectRatio();


    };
}