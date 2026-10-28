//
// Project: raytracer-test
// File: rayTrace/ray.h
// Purpose: Defines the ray primitive used for scene traversal and intersections.
// Author: cdemin
// Updated: 2026-10-28
//

#pragma once

#include "./qbLinearAlgebra/qbVector.h"

namespace raytrace {
    class Ray {
    public:
        //defualt constructor
        Ray(const qbVector<double> &point1, const qbVector<double> &point2);

        // getter functions
        qbVector<double> GetPoint1() const;
        qbVector<double> GetPoint2() const;

        // --------------------------------
        qbVector<double> m_point1 = qbVector<double>(3);
        qbVector<double> m_point2 = qbVector<double>(3);
        qbVector<double> m_lab = qbVector<double>(3); // the vector *between* point 1 and 2


    };
}
