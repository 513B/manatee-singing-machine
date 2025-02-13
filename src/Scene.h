#ifndef SCENE_H
#define SCENE_H

#include "Listener.h"
#include "SoundSource.h"
#include "Reflection.h"
#include <vector>
#include <memory>

class Scene {
public:
    // 构造函数
    Scene(const Listener& listener_);

    // 添加音源到场景
    void addSoundSource(const SoundSource& soundSource);

    // 添加反射面到场景
    void addReflectionSurface(const std::shared_ptr<Reflection>& reflectionSurface);

    // 更新场景中的对象（例如音源或反射面位置变化）
    void update(double deltaTime);

    // 生成最终音频输出，考虑音源、反射面、听众的影响
    std::vector<double> generateAudioOutput();

    // 获取场景中的音源
    const std::vector<SoundSource>& getSoundSources() const;

    // 获取场景中的反射面
    const std::vector<std::shared_ptr<Reflection>>& getReflectionSurfaces() const;

    // 获取听众
    const Listener& getListener() const;

private:
    Listener listener;  // 场景中的听众
    std::vector<SoundSource> soundSources;  // 场景中的音源
    std::vector<std::shared_ptr<Reflection>> reflectionSurfaces;  // 场景中的反射面
};

#endif // SCENE_H

