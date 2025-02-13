# 设置 CMake 的最低版本要求及项目名称
cmake_minimum_required(VERSION 3.27)
project(SpatialAudioProject)

# 指定使用的 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置输出目录（可选）
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 查找 libsndfile 包
find_package(SndFile REQUIRED)

# 包含头文件目录
include_directories(${SNDFILE_INCLUDE_DIRS})

# 定义项目的源文件
set(SOURCES
        src/main.cpp
        src/SoundSource.cpp
        src/Listener.cpp
        src/AudioProcessor.cpp
        src/AudioProcessor.h
        src/minimp3.h
        src/minimp3_ex.h
        src/SoundEngine.cpp
        src/SoundEngine.h
        src/Reflection.cpp
        src/Reflection.h
        src/PlaneReflection.cpp
        src/PlaneReflection.h
        src/SphereReflection.cpp
        src/SphereReflection.h
        src/CylinderReflection.cpp
        src/CylinderReflection.h
        src/Scene.cpp
        src/Scene.h
)

# 创建可执行文件
add_executable(SpatialAudioProject ${SOURCES})

# 链接 libsndfile 库
target_link_libraries(SpatialAudioProject PRIVATE SndFile::sndfile)