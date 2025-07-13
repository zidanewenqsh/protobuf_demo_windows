# Protobuf 示例项目

这是一个简单的 Protocol Buffers 示例项目，在 Windows 平台上使用 CMake 和 Visual Studio 2015 构建。本项目使用标准的 Protobuf 运行时。

## 项目结构

```
├── CMakeLists.txt       # CMake 配置文件
├── build.sh             # 构建脚本
├── generate_proto.sh    # 生成 Protobuf 代码脚本
├── install_vs2015.sh    # 安装最新版本 Protobuf 的脚本
├── 3rdparty/            # 第三方库
│   ├── protobuf-3.6.1/
│   │   ├── include/     # Protobuf 头文件
│   │   ├── lib/         # Protobuf 库文件
│   │   └── bin/         # Protobuf 可执行文件 (包括protoc.exe)
│   └── protobuf-3.21.12/ # 新版本 Protobuf (可选)
│       ├── include/     # Protobuf 头文件
│       ├── lib/         # Protobuf 库文件
│       └── bin/         # Protobuf 可执行文件 (包括protoc.exe)
├── protos/              # Protobuf 定义文件
│   ├── addressbook.proto # 地址簿消息定义
│   ├── contact.proto    # 联系人消息定义
│   ├── face.proto       # 人脸算法消息定义
│   ├── item.proto       # 物品消息定义
│   ├── person.proto     # 人员消息定义
│   └── phonebook.proto  # 电话簿消息定义
├── include/             # 生成的 Protobuf 头文件
├── src/                 # C++ 源代码
│   └── demo/            # 示例程序源代码和生成的 Protobuf 源文件
│       ├── addressbook.cpp     # 地址簿示例程序
│       ├── addressbook.pb.cc   # 地址簿生成的 Protobuf 源文件
│       ├── contact.cpp         # 联系人示例程序
│       ├── contact.pb.cc       # 联系人生成的 Protobuf 源文件
│       ├── face.pb.cc          # 人脸算法生成的 Protobuf 源文件
│       ├── item.cpp            # 物品示例程序
│       ├── item.pb.cc          # 物品生成的 Protobuf 源文件
│       ├── person.cpp          # 人员示例程序
│       ├── person.pb.cc        # 人员生成的 Protobuf 源文件
│       ├── phonebook.cpp       # 电话簿示例程序
│       └── phonebook.pb.cc     # 电话簿生成的 Protobuf 源文件
└── assets/              # 辅助资源
    └── protobuf-3.6.1/  # Protobuf 编译脚本
```

## 环境要求

- Visual Studio 2015 或更高版本 (VS2015、VS2017、VS2019、VS2022 均可)
- CMake (建议使用 3.21 或更高版本，可同时支持 VS2015 到 VS2022)
- Protocol Buffers (支持 3.6.1 或 3.21.12 等版本)
- Git Bash 或其他可以运行 shell 脚本的工具（在 Windows 上）

> **CMake 版本说明**：虽然项目最低要求 CMake 3.10，但建议使用 CMake 3.21 或更高版本。CMake 3.21+ 提供了更好的 Visual Studio 兼容性，可以同时支持从 VS2015 到 VS2022 的所有版本，使项目在不同 Visual Studio 环境下都能正常构建。

## 准备工作

项目支持多个版本的 Protocol Buffers 库：
- 默认版本: `3.21.12`
- 可选版本: `3.6.1` 或其他版本

## 安装 Protocol Buffers

本项目提供了两种手动编译 Protocol Buffers 的方法，它们的主要区别在于编译的版本不同，以及运行时库的处理方式不同。

### 方法一：使用 install_vs2015.sh 安装 3.21.12 版本 (推荐)

项目提供了 `install_vs2015.sh` 脚本，可以自动下载、编译和安装 Protocol Buffers 3.21.12：

1. 在 Git Bash 中运行脚本：
   ```
   ./install_vs2015.sh
   ```

2. 脚本会自动执行以下操作：
   - 克隆 Protocol Buffers 仓库
   - 切换到 v3.21.12 版本
   - 使用 CMake 和 Visual Studio 2015 编译库
   - 将编译好的文件安装到 `protobuf_install` 目录

3. 将生成的文件复制到项目的 `3rdparty/protobuf-3.21.12` 目录：
   - 可执行文件: `protobuf_install/bin/protoc.exe` → `3rdparty/protobuf-3.21.12/bin/`
   - 库文件: `protobuf_install/lib/` → `3rdparty/protobuf-3.21.12/lib/`
   - 头文件: `protobuf_install/include/` → `3rdparty/protobuf-3.21.12/include/`

**注意**：使用 install_vs2015.sh 安装的 Protobuf 3.21.12 库不需要在 CMakeLists.txt 中额外设置静态运行时库（/MT）。这个版本的 Protobuf 在 Windows 上可以同时支持静态和动态运行时库，不会出现兼容性问题。

### 方法二：手动编译 Protocol Buffers 3.6.1 版本 (可选)

如果您需要使用 Protobuf 3.6.1 版本，请按照以下步骤操作：

1. 从 GitHub Releases 页面下载 Protobuf 3.6.1 源代码包：
   ```
   https://github.com/protocolbuffers/protobuf/releases/download/v3.6.1/protobuf-all-3.6.1.zip
   ```

2. 解压下载的 zip 文件：
   ```
   unzip protobuf-all-3.6.1.zip
   ```

3. 将 `assets/protobuf-3.6.1/build.sh` 脚本复制到解压后的 `protobuf-3.6.1` 目录

4. 在 Visual Studio 2015 命令提示符中运行脚本：
   ```
   # 打开 VS2015 x64 Native Tools Command Prompt
   cd path/to/protobuf-3.6.1
   bash build.sh
   ```

5. 编译完成后，库文件将安装在 `protobuf-3.6.1/install` 目录中：
   - 可执行文件: `install/bin/protoc.exe`
   - 库文件: `install/lib/libprotobuf.lib` 等
   - 头文件: `install/include/google/protobuf/`

6. 将编译好的文件复制到项目的 `3rdparty/protobuf-3.6.1` 目录中

**重要说明**：Protobuf 3.6.1 版本在 Windows 平台上必须使用静态运行时库（/MT）进行编译，否则会出现链接错误或运行时问题。这是 3.6.1 版本的已知限制，因此本项目的 CMakeLists.txt 中特别设置了使用静态运行时库。而 3.21.12 版本已经解决了这个问题，可以更灵活地处理运行时库选项。

## 构建步骤

1. 首先生成 Protobuf 代码：
   ```
   ./generate_proto.sh
   ```
   这将处理 protos/ 目录下的所有 .proto 文件，并生成对应的 C++ 代码：
   - 头文件 (.h) 将放在 include/ 目录
   - 源文件 (.cc) 将放在 src/demo/ 目录

   注意：generate_proto.sh 默认使用 Protobuf 3.21.12 版本。

2. 运行构建脚本：
   ```
   ./build.sh
   ```
   
   或在 Windows 命令提示符中：
   ```
   sh build.sh
   ```

   注意：CMakeLists.txt 默认使用 Protobuf 3.21.12 版本。如需使用其他版本，可以通过命令行参数指定：
   ```
   cmake -DPROTOBUF_VERSION=3.6.1 ..
   ```

   如果您想使用不同版本的 Visual Studio，可以通过 -G 参数指定生成器：
   ```
   # VS2015
   cmake -G "Visual Studio 14 2015" -A x64 ..
   
   # VS2017
   cmake -G "Visual Studio 15 2017" -A x64 ..
   
   # VS2019
   cmake -G "Visual Studio 16 2019" -A x64 ..
   
   # VS2022
   cmake -G "Visual Studio 17 2022" -A x64 ..
   ```

3. 构建完成后，五个可执行文件将位于 `build/Release/` 目录下：
   - `addressbook_demo.exe` - 地址簿示例
   - `contact_demo.exe` - 联系人示例
   - `item_demo.exe` - 物品示例
   - `person_demo.exe` - 人员示例
   - `phonebook_demo.exe` - 电话簿示例

## 运行

在 Windows 上运行生成的可执行文件，例如：
```
.\build\Release\person_demo.exe
```

## 运行时库兼容性

本项目使用静态链接的C++运行时库（/MT）。如果您需要使用其他依赖动态运行时库（/MD）的库（如OpenCV预编译库），您有两个选择：

1. 修改 CMakeLists.txt 中的运行时库设置，改为使用动态运行时库（/MD）
   - 注意：如果使用 Protobuf 3.6.1 版本，必须使用静态运行时库（/MT）
   - 如果使用 Protobuf 3.21.12 版本，可以灵活选择运行时库类型

2. 使用与本项目相同运行时库选项（/MT）编译的库版本

请注意，混合使用不同运行时库编译的代码会导致链接错误和潜在的运行时问题。 