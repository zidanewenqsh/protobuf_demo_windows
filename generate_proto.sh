#!/bin/sh

# 设置默认 Protobuf 版本
PROTOBUF_VERSION="3.21.12"

echo "使用 Protobuf 版本: ${PROTOBUF_VERSION}"

# 检查 protoc 是否存在
PROTOC_PATH="./3rdparty/protobuf-${PROTOBUF_VERSION}/bin/protoc.exe"
if [ ! -f "$PROTOC_PATH" ]; then
  echo "错误: protoc 编译器不存在: $PROTOC_PATH"
  exit 1
fi

# 创建输出目录
mkdir -p generated
mkdir -p include
mkdir -p src/demo

# 运行 protoc 编译器生成 C++ 代码，处理所有proto文件
for proto_file in ./protos/*.proto
do
  "$PROTOC_PATH" --cpp_out=./generated --proto_path=./protos "$proto_file"
done

# 移动生成的文件到对应目录
for h_file in ./generated/*.h
do
  mv "$h_file" ./include/
done

for cc_file in ./generated/*.cc
do
  mv "$cc_file" ./src/demo/
done

echo "已生成 Protobuf 文件:"
echo "头文件(.h):"
ls -la ./include/
echo "源文件(.cc):"
ls -la ./src/demo/ 