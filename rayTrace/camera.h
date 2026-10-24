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

        // function to get a ray
        Ray GenerateRay(float projectScreenX, float projectScreenY); // x and y define position on screen that we generate a ray for

        // update camera geometry
        void UpdateCamera();

    private:
        qbVector<double> m_cameraPosition = qbVector<double>(3);
        qbVector<double> m_cameraLookAt = qbVector<double>(3);
        qbVector<double> m_cameraUp = qbVector<double>(3);
        double m_cameraLength;
        double m_cameraHorizontalSize;
        double m_cameraAspectRatio;

        qbVector<double> m_alignment = qbVector<double>(3);
        qbVector<double> m_projScreenU = qbVector<double>(3);
        qbVector<double> m_projScreenV = qbVector<double>(3);
        qbVector<double> m_projScreenCenter = qbVector<double>(3);
    };
}