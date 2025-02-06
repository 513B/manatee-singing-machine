#ifndef AUDIO_PROCESSOR_H
#define AUDIO_PROCESSOR_H

#include <vector>
#include <string>

class AudioProcessor {
public:
    AudioProcessor(); // 构造函数
    ~AudioProcessor(); // 析构函数

    bool load(const std::string& filename); // 加载并解码 MP3 文件

    const std::vector<float> & getAudioBuffer() const; // 获取音频缓冲区
    int getSampleRate() const; // 获取采样率
    int getNumChannels() const; // 获取声道数

private:
    int sampleRate; // 音频采样率
    int numChannels; // 声道数
    std::vector<float> audioBuffer; // 存储 PCM 数据（float 类型）
};

#endif // AUDIO_PROCESSOR_H
