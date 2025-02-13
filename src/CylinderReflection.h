#ifndef CYLINDER_REFLECTION_H
#define CYLINDER_REFLECTION_H

#include "Reflection.h"

class CylinderReflection : public Reflection {
public:
    CylinderReflection(const std::vector<double>& axis_, double radius_, double absorptionCoeff_, double scatteringCoeff_);

    std::vector<double> reflect(const std::vector<double>& incidentDirection) const override;
    std::vector<SoundSource> generateSubSource(const std::vector<double>& incidentDirection) const;

private:
    std::vector<double> axis;  // 圆柱轴方向
    double radius;             // 圆柱半径
};

#endif // CYLINDER_REFLECTION_H

