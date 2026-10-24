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
