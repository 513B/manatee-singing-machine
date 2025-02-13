#include "SphereReflection.h"
#include <cmath>

SphereReflection::SphereReflection(const std::vector<double>& center_, double radius_, double absorptionCoeff_, double scatteringCoeff_)
        : Reflection(absorptionCoeff_, scatteringCoeff_), center(center_), radius(radius_) {}

std::vector<double> SphereReflection::reflect(const std::vector<double>& incidentDirection) const {
    // 计算声波与球心的方向
    std::vector<double> directionToCenter = {center[0] - incidentDirection[0], center[1] - incidentDirection[1], center[2] - incidentDirection[2]};
    double magnitude = std::sqrt(directionToCenter[0] * directionToCenter[0] + directionToCenter[1] * directionToCenter[1] + directionToCenter[2] * directionToCenter[2]);

    // 计算反射方向（简化为直接反射）
    std::vector<double> reflectionDirection = {
            incidentDirection[0] - 2 * directionToCenter[0] * (incidentDirection[0] / magnitude),
            incidentDirection[1] - 2 * directionToCenter[1] * (incidentDirection[1] / magnitude),
            incidentDirection[2] - 2 * directionToCenter[2] * (incidentDirection[2] / magnitude)
    };
    return reflectionDirection;
}


