//
// Created by 22793 on 2025/2/10.
//

#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include "Listener.h"
#include "SoundSource.h"
#include <vector>
#include <cmath>

class SoundEngine {
public:
    SoundEngine() {}

    // 生成听众的音频信号，分别计算左耳和右耳的声音
    std::vector<double> generateAudioForListener(const Listener& listener, const std::vector<SoundSource>& soundSources);

private:
    // 计算从听众到音源的方向角
    double calculateAzimuth(const std::vector<double>& sourcePosition, const std::vector<double>& listenerPosition);

    // 计算耳朵朝向与声源方向的夹角
    double calculateAngleBetweenListenerOrientationAndEar(const Listener& listener, const std::vector<double>& sourcePosition, double earOffset);
};

#endif
