#!/bin/sh

# 创建输出目录
mkdir -p generated
mkdir -p include
mkdir -p src/demo

# 运行 protoc 编译器生成 C++ 代码，处理所有proto文件
for proto_file in ./protos/*.proto
do
  ./3rdparty/protobuf-3.6.1/bin/protoc.exe --cpp_out=./generated --proto_path=./protos "$proto_file"
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