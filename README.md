# Protobuf 示例项目

这是一个简单的 Protocol Buffers 示例项目，在 Windows 平台上使用 CMake 和 Visual Studio 2015 构建。本项目使用标准的 Protobuf 运行时。

## 项目结构

```
├── CMakeLists.txt       # CMake 配置文件
├── build.sh             # 构建脚本
├── generate_proto.sh    # 生成 Protobuf 代码脚本
├── 3rdparty/            # 第三方库
│   └── protobuf-3.6.1/
│       ├── include/     # Protobuf 头文件
│       ├── lib/         # Protobuf 库文件
│       └── bin/         # Protobuf 可执行文件 (包括protoc.exe)
├── protos/              # Protobuf 定义文件
│   ├── addressbook.proto # 地址簿消息定义
│   ├── contact.proto    # 联系人消息定义
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

- Visual Studio 2015
- CMake (3.10 或更高版本)
- Protocol Buffers 3.6.1
- Git Bash 或其他可以运行 shell 脚本的工具（在 Windows 上）

## 准备工作

项目已包含 Protocol Buffers 3.6.1 库：
- 编译器: `3rdparty/protobuf-3.6.1/bin/protoc.exe`
- 头文件: `3rdparty/protobuf-3.6.1/include/`
- 库文件: `3rdparty/protobuf-3.6.1/lib/`

## 自行编译 Protocol Buffers 3.6.1 (可选)

如果您需要自行编译 Protocol Buffers 库，请按照以下步骤操作：

1. 下载 Protocol Buffers 3.6.1 源代码：
   ```
   git clone https://github.com/protocolbuffers/protobuf.git -b v3.6.1
   ```

2. 将 `assets/protobuf-3.6.1/build.sh` 脚本复制到 protobuf 源代码根目录

3. 在 Visual Studio 2015 命令提示符中运行脚本：
   ```
   # 打开 VS2015 x64 Native Tools Command Prompt
   cd path/to/protobuf-3.6.1
   bash build.sh
   ```

4. 编译完成后，库文件将安装在 `protobuf-3.6.1/install` 目录中：
   - 可执行文件: `install/bin/protoc.exe`
   - 库文件: `install/lib/libprotobuf.lib` 等
   - 头文件: `install/include/google/protobuf/`

5. 将编译好的文件复制到项目的 `3rdparty/protobuf-3.6.1` 目录中

**注意**：编译 Protocol Buffers 时使用的运行时库选项（/MT 或 /MD）必须与您的项目一致。本项目默认使用静态运行时库（/MT）。

## 构建步骤

1. 首先生成 Protobuf 代码：
   ```
   ./generate_proto.sh
   ```
   这将处理 protos/ 目录下的所有 .proto 文件，并生成对应的 C++ 代码：
   - 头文件 (.h) 将放在 include/ 目录
   - 源文件 (.cc) 将放在 src/demo/ 目录

2. 运行构建脚本：
   ```
   ./build.sh
   ```
   
   或在 Windows 命令提示符中：
   ```
   sh build.sh
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
2. 使用与本项目相同运行时库选项（/MT）编译的库版本

请注意，混合使用不同运行时库编译的代码会导致链接错误和潜在的运行时问题。 