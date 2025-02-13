#include "Scene.h"
#include "SoundEngine.h"
#include <iostream>

Scene::Scene(const Listener& listener_) : listener(listener_) {}

void Scene::addSoundSource(const SoundSource& soundSource) {
    soundSources.push_back(soundSource);
}

void Scene::addReflectionSurface(const std::shared_ptr<Reflection>& reflectionSurface) {
    reflectionSurfaces.push_back(reflectionSurface);
}

void Scene::update(double deltaTime) {
    // 在这里可以处理音源、反射面等的更新逻辑
    // 比如：更新音源的位置、听众的位置、反射面的状态等
}

std::vector<double> Scene::generateAudioOutput() {
    std::vector<double> finalAudio;  // 存放最终的音频输出

    SoundEngine soundEngine;

    // 对每个音源，生成听众处的音频信号
    std::vector<double> listenerAudio = soundEngine.generateAudioForListener(listener, soundSources);

    // 将音源音频数据加入最终输出
    finalAudio.insert(finalAudio.end(), listenerAudio.begin(), listenerAudio.end());

    // 处理反射面
    for (const auto& reflectionSurface : reflectionSurfaces) {
        // 为反射面生成次声源，并添加到最终音频，注意这里尚未完善
        auto subSources = reflectionSurface->generateSubSource({0, 0, 0}, listener, soundSources);
        for (const auto& subSource : subSources) {
            std::vector<double> subSourceAudio = soundEngine.generateAudioForListener(listener, {subSource});
            finalAudio.insert(finalAudio.end(), subSourceAudio.begin(), subSourceAudio.end());
        }
    }

    return finalAudio;
}

const std::vector<SoundSource>& Scene::getSoundSources() const {
    return soundSources;
}

const std::vector<std::shared_ptr<Reflection>>& Scene::getReflectionSurfaces() const {
    return reflectionSurfaces;
}

const Listener& Scene::getListener() const {
    return listener;
}
