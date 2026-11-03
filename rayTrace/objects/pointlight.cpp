//
// Created by cdemin on 11/3/26.
//

#include "pointlight.h"

// default constructor and destructor
raytrace::PointLight::PointLight() {
    std::cout << "PointLight::PointLight(): Constructing Point Light" << std::endl;

    m_color = qbVector<double> {std::vector<double>{1.0, 1.0, 1.0}};
    m_intensity = 1.0;
}

raytrace::PointLight::~PointLight() {
    std::cout << "PointLight::~PointLight(): Destructing Point Light" << std::endl;
}


// function to compute illumination
bool raytrace::PointLight::ComputeIllumination(const qbVector<double> &intPoint,
    const qbVector<double> &localNorm,
    const std::vector<std::shared_ptr<raytrace::ObjectBase> > &objectList,
    const std::shared_ptr<raytrace::ObjectBase> &currentObject,
    qbVector<double> &color, double &intensity) {
    // ===========================================================



}
