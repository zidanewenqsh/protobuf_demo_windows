#!/bin/sh

rm -rf build

# 创建构建目录
mkdir -p build

# 进入构建目录
cd build

# 生成 CMake 构建文件，使用 Visual Studio 2015 生成器
# cmake -G "Visual Studio 14 2015" -A x64 ..
cmake -G "Visual Studio 14 2015" ..

# 编译项目
cmake --build . --config Release 