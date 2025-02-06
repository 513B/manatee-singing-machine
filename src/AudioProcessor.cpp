//
// Created by 22793 on 2025/2/5.
//
#include "AudioProcessor.h"
#define MINIMP3_IMPLEMENTATION
#include "minimp3.h"
#include "minimp3_ex.h"
#include <fstream>
#include <iostream>

AudioProcessor::AudioProcessor()
        : sampleRate(0), numChannels(0)
{
}

AudioProcessor::~AudioProcessor()
{
}

bool AudioProcessor::load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer(size);
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        std::cerr << "读取文件失败: " << filename << std::endl;
        return false;
    }

    mp3dec_t mp3d;
    mp3dec_init(&mp3d);

    mp3dec_frame_info_t info;
    size_t offset = 0;

    while (offset < buffer.size()) {
        mp3d_sample_t pcm[1152 * 2]; // 每帧最多1152个样本，立体声
        int ret = mp3dec_decode_frame(&mp3d, buffer.data() + offset, buffer.size() - offset, pcm, &info);
        

        if (ret < 0) {
            std::cerr << "解码错误在偏移量: " << offset << std::endl;
            break;
        }

        if (info.frame_bytes == 0) {
            break; // 没有更多帧
        }

        // 保存采样率和声道数
        if (sampleRate == 0) {
            sampleRate = info.hz;
        }
        if (numChannels == 0) {
            numChannels = info.channels;
            if (numChannels > 2) {
                std::cerr << "当前实现只支持单声道或立体声，但检测到 " << numChannels << " 声道。" << std::endl;
                return false;
            }
        }

        // 检查帧的一致性
        if (info.channels != numChannels) {
            std::cerr << "不同帧的声道数不一致，当前实现不支持。" << std::endl;
            return false;
        }

        // 将PCM数据转换并添加到缓冲区
        for (int i = 0; i < ret * info.channels; ++i) {
            float scaled_value = static_cast<float>(pcm[i]) / 32768.0f;
            audioBuffer.push_back(scaled_value);


        }

        offset += info.frame_bytes;
    }

    // 确保解码了有效数据
    if (audioBuffer.empty()) {
        std::cerr << "解码失败，没有音频数据。" << std::endl;
        return false;
    }

    return true;
}


const std::vector<float> & AudioProcessor::getAudioBuffer() const {
    return audioBuffer;
}

int AudioProcessor::getSampleRate() const
{
    return sampleRate;
}

int AudioProcessor::getNumChannels() const
{
    return numChannels;
}
