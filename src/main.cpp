#include <iostream>
#include "AudioProcessor.h"

int main() {
    // 创建 AudioProcessor 对象
    AudioProcessor audioProcessor;

    // MP3 文件路径
    std::string mp3FilePath = "E:/obj_wo3DlMOGwrbDjj7DisKw_14096462011_9d26_58c6_888e_15e7c4f3aa6cf5c5b41acb2aa665baf0.mp3";  // 请替换成你的MP3文件路径

    // 加载 MP3 文件
    if (!audioProcessor.load(mp3FilePath)) {
        std::cerr << "wrong mp3 file path or file not exist!" << std::endl;
        return 1;
    }

    // 输出音频前100个样本
    const auto& audioBuffer = audioProcessor.getAudioBuffer();
    std::cout << "Audio buffer: " << std::endl;
    for (int i = 0; i < 100000 && i < audioBuffer.size(); ++i) {
        std::cout << audioBuffer[i] << std::endl;
    }

    return 0;
}

