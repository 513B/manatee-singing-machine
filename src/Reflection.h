#ifndef REFLECTION_H
#define REFLECTION_H

#include <vector>
#include <cmath>
#include "SoundSource.h"

class Reflection {
public:
    // 构造函数，定义反射面法向量，并设置吸收系数、散射强度等物理属性
    Reflection(double absorptionCoeff_, double scatteringCoeff_);

    // 计算反射声波的方向
    virtual std::vector<double> reflect(const std::vector<double>& incidentDirection) const = 0;

    // 根据反射面生成次声源
    virtual std::vector<SoundSource> generateSubSource(const std::vector<double>& incidentDirection) const = 0;

protected:
    double absorptionCoeff;             // 吸收系数 (0 到 1)，0表示无吸收，1表示完全吸收
    double scatteringCoeff;             // 散射系数 (0 到 1)，表示散射的程度
    double reflectionCoeff;             // 反射系数 (0 到 1)，表示反射强度
};

#endif // REFLECTION_H


