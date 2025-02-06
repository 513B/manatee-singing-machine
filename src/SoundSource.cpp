
//
// Created by 22793 on 2025/1/27.
//
// SoundSource.cpp
#include "SoundSource.h"

SoundSource::SoundSource(double x, double y, double z, const std::vector<float>& audioData_)
        : position({x, y, z}), audioData(audioData_) {}

std::vector<float> SoundSource::getAudioData() const {
    return audioData;
}

void SoundSource::setPosition(double x, double y, double z) {
    position = {x, y, z};
}

std::vector<double> SoundSource::getPosition() const {
    return position;
}