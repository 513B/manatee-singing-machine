#ifndef PLANE_REFLECTION_H
#define PLANE_REFLECTION_H

#include "Reflection.h"

class PlaneReflection : public Reflection {
public:
    PlaneReflection(const std::vector<double>& normal_, double absorptionCoeff_, double scatteringCoeff_);

    std::vector<double> reflect(const std::vector<double>& incidentDirection) const override;
    std::vector<SoundSource> generateSubSource(const std::vector<double>& incidentDirection) const override;

private:
    std::vector<double> normal;  // 反射面法向量
};

#endif // PLANE_REFLECTION_H

