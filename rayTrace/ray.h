//
// Created by cdemin on 10/18/26.
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
        qbVector<double> m_point1 (3);
        qbVector<double> m_point2 (3);
        qbVector<double> m_lab (3); // the vector *between* point 1 and 2


    };
}