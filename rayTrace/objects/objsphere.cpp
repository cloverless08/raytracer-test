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
    // ===================================



}
