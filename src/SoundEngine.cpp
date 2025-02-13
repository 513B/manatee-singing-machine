//
// Created by 22793 on 2025/2/10.
//
#include "SoundEngine.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

// 计算从听众到音源的方向角
double SoundEngine::calculateAzimuth(const std::vector<double>& sourcePosition, const std::vector<double>& listenerPosition) {
    double dx = sourcePosition[0] - listenerPosition[0];
    double dy = sourcePosition[1] - listenerPosition[1];
    return std::atan2(dy, dx);  // 返回方向角
}

// 计算耳朵朝向与声源方向的夹角
double SoundEngine::calculateAngleBetweenListenerOrientationAndEar(const Listener& listener, const std::vector<double>& sourcePosition, double earOffset) {
    auto listenerPosition = listener.getPosition();
    double azimuthToSource = calculateAzimuth(sourcePosition, listenerPosition); // 计算源与听众的方向角
    double listenerOrientation = listener.getOrientation()[0];  // 听众朝向的 yaw 角度

    // 耳朵的偏移：左耳偏移 -90°，右耳偏移 +90°
    double earOrientation = listenerOrientation + earOffset;

    // 计算方向夹角，保证夹角在 -π 到 π 之间
    double angleDifference = azimuthToSource - earOrientation;
    if (angleDifference > M_PI) {
        angleDifference -= 2 * M_PI;
    } else if (angleDifference < -M_PI) {
        angleDifference += 2 * M_PI;
    }

    return std::abs(angleDifference); // 返回绝对夹角
}

// 生成听众的音频信号
std::vector<double> SoundEngine::generateAudioForListener(const Listener& listener, const std::vector<SoundSource>& soundSources) {
    std::vector<double> finalAudio;  // 初始化最终音频数据（左右耳合成）

    for (const auto& source : soundSources) {
        auto sourcePosition = source.getPosition();
        auto listenerPosition = listener.getPosition();
        double earDistance = listener.getEarDistance();

        // 计算源与听众的相对距离
        double dx = listenerPosition[0] - sourcePosition[0];
        double dy = listenerPosition[1] - sourcePosition[1];
        double dz = listenerPosition[2] - sourcePosition[2];
        double distance = std::sqrt(dx*dx + dy*dy + dz*dz);

        // 可以替换其它的衰减规律
        double attenuation = 1.0 / (distance * distance);

        // 分别计算左耳和右耳的增益
        double leftEarOffset  =  M_PI / 2;
        double rightEarOffset = -M_PI / 2;

        double leftEarAngle = calculateAngleBetweenListenerOrientationAndEar(listener, sourcePosition, leftEarOffset);
        double rightEarAngle = calculateAngleBetweenListenerOrientationAndEar(listener, sourcePosition, rightEarOffset);

        // 这部分增益计算可以使用更高级的工具
        double maxAngle = M_PI / 2;  // 最大有效角度
        double leftEarGain = std::max(0.0, 1.0 - leftEarAngle / maxAngle);
        double rightEarGain = std::max(0.0, 1.0 - rightEarAngle / maxAngle);

        // 获取音源的音频数据
        auto audioData = source.getAudioData();

        // 初始化最终音频数据（如果这是第一次音源）
        if (finalAudio.empty()) {
            finalAudio.resize(audioData.size(), 0.0);
        }

        // 分别为左耳和右耳添加音频数据
        for (size_t i = 0; i < audioData.size(); ++i) {
            finalAudio[i] += attenuation * audioData[i] * leftEarGain;  // 左耳增益
            finalAudio[i] += attenuation * audioData[i] * rightEarGain; // 右耳增益
        }
    }

    return finalAudio;
}

