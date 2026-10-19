//
// Created by cdemin on 10/18/26.
//

#pragma once

#include "../qbLinearAlgebra/qbVector.hpp"

namespace RayTrace {
    class Ray {
    public:
        //defualt constructor
        Ray(const qbVector<double> &point1, const qbVector<double> &point2);

        // getter functions
        qbVector<double> GetPoint1() const;
        qbVector<double> GetPoint2() const;



    };
}