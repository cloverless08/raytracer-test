//
// Created by cdemin on 11/1/26.
//

#include "objsphere.h"

#include <cmath>

raytrace::ObjSphere::ObjSphere() {
    std::cout << "ObjSphere::ObjSphere(): Constructing Sphere Object" << std::endl;
};

raytrace::ObjSphere::~ObjSphere() {
    std::cout << "ObjSphere::~ObjSphere(): Destructing Sphere Object" << std::endl;
}


// define intersection test
bool raytrace::ObjSphere::TestIntersection(
    const Ray &castRay,
    qbVector<double> &intPoint,
    qbVector<double> &localNorm,
    qbVector<double> &localColor) {
    constexpr double radius = 1.0;
    const double a = qbVector<double>::dot(castRay.m_lab, castRay.m_lab);
    if (a == 0.0) {
        return false;
    }

    const double b = 2.0 * qbVector<double>::dot(castRay.m_point1, castRay.m_lab);
    const double c = qbVector<double>::dot(castRay.m_point1, castRay.m_point1) - radius * radius;
    const double discriminant = b * b - 4.0 * a * c;
    if (discriminant < 0.0) {
        return false;
    }

    const double root = std::sqrt(discriminant);
    const double t1 = (-b - root) / (2.0 * a);
    const double t2 = (-b + root) / (2.0 * a);
    double t = t1;
    if (t <= 0.0) {
        t = t2;
    }
    if (t <= 0.0) {
        return false;
    }

    intPoint = castRay.m_point1 + (castRay.m_lab * t);
    localNorm = intPoint;
    localNorm.Normalize();
    localColor = m_baseColor;
    return true;
}
