//
// Created by 22793 on 2025/1/27.
//
// SoundSource.h
#ifndef SOUNDSOURCE_H
#define SOUNDSOURCE_H

#include <vector>

class SoundSource {
public:
    SoundSource(double x, double y, double z, const std::vector<float>& audioData);

    std::vector<float> getAudioData() const;
    void setPosition(double x, double y, double z);
    std::vector<double> getPosition() const;

private:
    std::vector<double> position; // {x, y, z}
    std::vector<float> audioData;
};

#endif // SOUNDSOURCE_H