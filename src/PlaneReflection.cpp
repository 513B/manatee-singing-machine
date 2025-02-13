#include "PlaneReflection.h"
#include <iostream>
#include <cmath>

PlaneReflection::PlaneReflection(const std::vector<double>& normal_, double absorptionCoeff_, double scatteringCoeff_)
        : Reflection(absorptionCoeff_, scatteringCoeff_), normal(normal_) {
    // 法向量归一化
    double magnitude = std::sqrt(normal_[0] * normal_[0] + normal_[1] * normal_[1] + normal_[2] * normal_[2]);
    for (size_t i = 0; i < normal_.size(); ++i) {
        normal[i] = normal_[i] / magnitude;
    }
}

std::vector<double> PlaneReflection::reflect(const std::vector<double>& incidentDirection) const {
    double dotProduct = incidentDirection[0] * normal[0] + incidentDirection[1] * normal[1] + incidentDirection[2] * normal[2];
    std::vector<double> reflectionDirection = {
            incidentDirection[0] - 2 * dotProduct * normal[0],
            incidentDirection[1] - 2 * dotProduct * normal[1],
            incidentDirection[2] - 2 * dotProduct * normal[2]
    };
    return reflectionDirection;
}

