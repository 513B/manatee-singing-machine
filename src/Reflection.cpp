#include "Reflection.h"
#include "SoundSource.h"
#include <iostream>
#include <cmath>
#include <random>

// 构造函数，初始化物理属性
Reflection::Reflection(double absorptionCoeff_, double scatteringCoeff_)
        : absorptionCoeff(absorptionCoeff_), scatteringCoeff(scatteringCoeff_) {
    reflectionCoeff = 1.0 - absorptionCoeff;  // 反射系数 = 1 - 吸收系数
}

// 基本散射模拟函数，考虑散射系数来调整次声源强度
std::vector<SoundSource> Reflection::generateSubSource(const std::vector<double>& incidentDirection) const {
    // 随机生成多个散射方向
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-M_PI / 4, M_PI / 4);  // 随机产生小角度来模拟散射

    // 次声源的数量，可以根据需要调整
    int numSubSources = 10;  // 假设生成10个次声源
    std::vector<SoundSource> subSources;

    for (int i = 0; i < numSubSources; ++i) {
        // 随机生成散射角度
        double scatterAngleX = dis(gen);  // 在X方向的散射
        double scatterAngleY = dis(gen);  // 在Y方向的散射

        // 生成次声源方向，这里将散射角度应用到入射方向上
        std::vector<double> subSourceDirection = {
                incidentDirection[0] + scatterAngleX,  // 方向X
                incidentDirection[1] + scatterAngleY,  // 方向Y
                incidentDirection[2]                   // 保持Z方向不变
        };

        // 考虑吸收和散射系数来调整次声源的强度
        for (size_t i = 0; i < subSourceDirection.size(); ++i) {
            subSourceDirection[i] *= scatteringCoeff;  // 修改散射后的方向强度
        }

        // 生成一个新的SoundSource对象，这里尚未实现音频数据的生成
        SoundSource subSource(subSourceDirection, {});  // 假设音频数据为空，后续可以根据需求填充
        subSources.push_back(subSource);
    }

    return subSources;  // 返回生成的多个次声源
}
