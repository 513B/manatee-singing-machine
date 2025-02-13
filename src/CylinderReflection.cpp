#include "CylinderReflection.h"
#include <cmath>

CylinderReflection::CylinderReflection(const std::vector<double>& axis_, double radius_, double absorptionCoeff_, double scatteringCoeff_)
        : Reflection(absorptionCoeff_, scatteringCoeff_), axis(axis_), radius(radius_) {}

std::vector<double> CylinderReflection::reflect(const std::vector<double>& incidentDirection) const {
    // 对于圆柱面，假设入射方向与轴线垂直进行反射（简化模拟）
    std::vector<double> reflectionDirection = {
            incidentDirection[0] - 2 * (incidentDirection[0] * axis[0]),
            incidentDirection[1] - 2 * (incidentDirection[1] * axis[1]),
            incidentDirection[2] - 2 * (incidentDirection[2] * axis[2])
    };
    return reflectionDirection;
}
