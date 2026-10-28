//
// Created by cdemin on 10/18/26.
//

#include "ray.h"

raytrace::Ray::Ray(const qbVector<double> &point1, const qbVector<double> &point2) {
    m_point1 = point1;
    m_point2 = point2;
    m_lab = m_point2 - m_point1;
}

// getter funcitons
qbVector<double> raytrace::Ray::GetPoint1() const {
    return m_point1;
}

qbVector<double> raytrace::Ray::GetPoint2() const {
    return m_point2;
}