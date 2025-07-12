#!/bin/bash

# Protocol Buffers 3.6.1 编译脚本 (Windows 环境)
# 此脚本需要在 Git Bash、WSL 或其他类似的 Unix shell 环境中运行
# 使用 Visual Studio 2015 编译

set -e  # 遇到错误时停止执行

# 显示彩色输出
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${YELLOW}Protocol Buffers 3.6.1 编译脚本 (Windows 环境 - VS2015)${NC}"
echo -e "${YELLOW}=====================================${NC}"

# 检查当前目录是否是 protobuf 源码根目录
if [ ! -f "configure.ac" ] || [ ! -d "src" ]; then
    echo -e "${RED}错误: 请在 protobuf 源码根目录下运行此脚本${NC}"
    exit 1
fi

# 创建安装目录
INSTALL_DIR="$(pwd)/install"
mkdir -p "$INSTALL_DIR"
echo -e "${GREEN}安装目录: $INSTALL_DIR${NC}"

# 检查是否有 CMake
if ! command -v cmake &> /dev/null; then
    echo -e "${RED}错误: 未找到 CMake，请安装 CMake 并确保其在 PATH 中${NC}"
    exit 1
fi

# 检查是否有 Visual Studio 2015 (通过检查 cl.exe)
if ! command -v cl &> /dev/null; then
    echo -e "${YELLOW}警告: 未找到 Visual Studio 编译器 (cl.exe)${NC}"
    echo -e "${YELLOW}请确保在 Visual Studio 2015 命令提示符中运行此脚本${NC}"
    echo -e "${YELLOW}例如: 'VS2015 x64 Native Tools Command Prompt'${NC}"
    echo -e "${YELLOW}是否继续? (y/n)${NC}"
    read -r response
    if [[ ! "$response" =~ ^[Yy]$ ]]; then
        exit 1
    fi
fi

# 使用 CMake 编译
echo -e "${GREEN}开始使用 CMake 和 Visual Studio 2015 编译 Protocol Buffers...${NC}"

# 创建并进入 build 目录
mkdir -p cmake/build
cd cmake/build

# 选择编译方式
echo -e "${YELLOW}请选择编译方式:${NC}"
echo -e "${YELLOW}1. 使用 NMake 编译 (推荐)${NC}"
echo -e "${YELLOW}2. 生成 Visual Studio 2015 解决方案${NC}"
read -r build_option

if [ "$build_option" == "2" ]; then
    # 创建 solution 目录
    mkdir -p solution
    cd solution
    
    echo -e "${GREEN}配置 CMake 生成 Visual Studio 2015 解决方案...${NC}"
    cmake -G "Visual Studio 14 2015 Win64" \
          -DCMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
          -Dprotobuf_BUILD_TESTS=OFF \
          ../..
    
    echo -e "${GREEN}已生成 Visual Studio 2015 解决方案${NC}"
    echo -e "${YELLOW}请在 Visual Studio 2015 中打开 protobuf.sln 文件${NC}"
    echo -e "${YELLOW}选择 Release 配置，然后构建 INSTALL 项目${NC}"
    
    # 返回到源码根目录
    cd ../../..
else
    # 创建 release 目录
    mkdir -p release
    cd release
    
    echo -e "${GREEN}配置 CMake...${NC}"
    cmake -G "NMake Makefiles" \
          -DCMAKE_BUILD_TYPE=Release \
          -DCMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
          -Dprotobuf_BUILD_TESTS=OFF \
          ../..
    
    echo -e "${GREEN}编译中...${NC}"
    nmake
    
    echo -e "${GREEN}安装中...${NC}"
    nmake install
    
    # 返回到源码根目录
    cd ../../..
    
    echo -e "${GREEN}编译完成!${NC}"
    echo -e "${GREEN}安装目录: $INSTALL_DIR${NC}"
    echo -e "${GREEN}可执行文件: $INSTALL_DIR/bin/protoc.exe${NC}"
    echo -e "${GREEN}库文件: $INSTALL_DIR/lib${NC}"
    echo -e "${GREEN}头文件: $INSTALL_DIR/include${NC}"
    
    # 显示 protoc 版本
    if [ -f "$INSTALL_DIR/bin/protoc.exe" ]; then
        echo -e "${GREEN}protoc 版本:${NC}"
        "$INSTALL_DIR/bin/protoc.exe" --version
    else
        echo -e "${RED}警告: protoc.exe 未找到${NC}"
    fi
fi

echo -e "${YELLOW}=====================================${NC}"
echo -e "${YELLOW}如果编译失败，请尝试以下方法:${NC}"
echo -e "${YELLOW}1. 确保在 Visual Studio 2015 命令提示符中运行此脚本${NC}"
echo -e "${YELLOW}   例如: 'VS2015 x64 Native Tools Command Prompt'${NC}"
echo -e "${YELLOW}2. 尝试手动执行以下命令:${NC}"
echo -e "${YELLOW}   cd cmake/build/release${NC}"
echo -e "${YELLOW}   cmake -G \"NMake Makefiles\" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../../../install ../..${NC}"
echo -e "${YELLOW}   nmake${NC}"
echo -e "${YELLOW}   nmake install${NC}"
echo -e "${YELLOW}3. 或者尝试使用 Visual Studio 2015 解决方案:${NC}"
echo -e "${YELLOW}   cd cmake/build${NC}"
echo -e "${YELLOW}   mkdir solution && cd solution${NC}"
echo -e "${YELLOW}   cmake -G \"Visual Studio 14 2015 Win64\" -DCMAKE_INSTALL_PREFIX=../../../install ../..${NC}"
echo -e "${YELLOW}   然后在 Visual Studio 2015 中打开 protobuf.sln${NC}"
