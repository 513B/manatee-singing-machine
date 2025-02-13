#ifndef SPHERE_REFLECTION_H
#define SPHERE_REFLECTION_H

#include "Reflection.h"

class SphereReflection : public Reflection {
public:
    SphereReflection(const std::vector<double>& center_, double radius_, double absorptionCoeff_, double scatteringCoeff_);

    std::vector<double> reflect(const std::vector<double>& incidentDirection) const override;
    std::vector<SoundSource> generateSubSource(const std::vector<double>& incidentDirection) const override;

private:
    std::vector<double> center;  // 球心位置
    double radius;              // 球的半径
};

#endif // SPHERE_REFLECTION_H

