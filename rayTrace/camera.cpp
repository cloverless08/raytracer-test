//
// Created by cdemin on 10/23/26.
//

#include "camera.h"
#include "ray.h"

#include<math.h>

rayTrace::Camera::Camera() {
    m_cameraPosition = qbVector<double> {std::vector<double> {0.0, -10.0, 0.0}}; // 10 units away form origin
    m_cameraLookAt = qbVector<double> {std::vector<double> {0.0, 0.0, 0.0}}; // looking at origin
    m_cameraUp = qbVector<double> {std::vector<double> {0.0, 0.0, 1.0}};

    m_cameraLength = 1.0;
    m_cameraAspectRatio = 1.0;
}

//paramter assigning functions
void rayTrace::Camera::SetPosition(const qbVector<double> &newPosition) {
    m_cameraPosition = newPosition;
}

void rayTrace::Camera::SetLookAt(const qbVector<double> &newLookAt) {
    m_cameraLookAt = newLookAt;
}

void rayTrace::Camera::SetUp(const qbVector<double> &newUp) {
    m_cameraUp = newUp;
}