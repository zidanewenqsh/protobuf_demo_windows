cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置编译器警告标志
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC 编译器
    add_compile_options(/W4 /WX)  # 使用 MSVC 的警告等级 4 和将警告视为错误
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC 或 Clang 编译器
    add_compile_options(-Wall -Wextra -g)
endif()

# 设置源代码和头文件目录
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(PROTOS_DIR protos)

# 手动指定 protoc.exe 路径（假设你已经安装了 protobuf，并知道 protoc 的路径）
set(PROTOC_PATH "D:/lib/protoc-3.19.4-win64/bin/protoc.exe")  # 替换为 protoc.exe 的实际路径

# 设置 protobuf 输出目录（生成的头文件和源文件）
set(PROTOBUF_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/include)
file(MAKE_DIRECTORY ${PROTOBUF_OUTPUT_DIR})

# 包含 protobuf 头文件目录
include_directories(${INCLUDE_DIR})
include_directories("D:/lib/protoc-3.19.4-win64/include")

# 查找 .proto 文件
file(GLOB PROTO_FILES "${PROTOS_DIR}/*.proto")

# 添加所有的源文件
file(GLOB CPP_FILES "${SRC_DIR}/*.cpp")

# 为每个源文件和对应的 .proto 文件创建可执行目标
foreach(CPP_FILE ${CPP_FILES})
    # 获取可执行文件名称
    get_filename_component(EXECUTABLE_NAME ${CPP_FILE} NAME_WE)

    # 获取对应的 .proto 文件路径
    set(PROTO_FILE "${CMAKE_SOURCE_DIR}/${PROTOS_DIR}/${EXECUTABLE_NAME}.proto")

    if(EXISTS ${PROTO_FILE})
        # message(STATUS "Found .proto file: ${PROTO_FILE}")
        # message(STATUS "PROTOC_PATH: ${PROTOC_PATH}")
        # 手动调用 protoc 命令生成 .pb.cc 和 .pb.h 文件
        add_custom_command(
            OUTPUT "${PROTOBUF_OUTPUT_DIR}/${EXECUTABLE_NAME}.pb.cc"
                   "${PROTOBUF_OUTPUT_DIR}/${EXECUTABLE_NAME}.pb.h"
            COMMAND ${PROTOC_PATH}
                    -I "${CMAKE_SOURCE_DIR}/${PROTOS_DIR}"
                    --cpp_out=${PROTOBUF_OUTPUT_DIR}
                    ${PROTO_FILE}
            DEPENDS ${PROTO_FILE}
            COMMENT "Generating C++ files from ${PROTO_FILE}"
        )
        # message(STATUS "Running protoc with command: ${PROTOC_PATH} -I ${CMAKE_SOURCE_DIR}/${PROTOS_DIR} --cpp_out=${PROTOBUF_OUTPUT_DIR} ${PROTO_FILE}")
        message(STATUS "${PROTOC_PATH} -I ${CMAKE_SOURCE_DIR}/${PROTOS_DIR} --cpp_out=${PROTOBUF_OUTPUT_DIR} ${PROTO_FILE}")

        # 输出生成的文件列表
        # message(STATUS "Generated files: ${PROTOBUF_OUTPUT_DIR}/${EXECUTABLE_NAME}.pb.cc, ${PROTOBUF_OUTPUT_DIR}/${EXECUTABLE_NAME}.pb.h")

        # 将生成的文件加入到目标
        file(GLOB PROTO_GEN_SRCS "${PROTOBUF_OUTPUT_DIR}/${EXECUTABLE_NAME}.pb.cc")
        file(GLOB PROTO_GEN_HDRS "${PROTOBUF_OUTPUT_DIR}/${EXECUTABLE_NAME}.pb.h")

        add_executable(${EXECUTABLE_NAME} ${CPP_FILE} ${PROTO_GEN_SRCS} ${PROTO_GEN_HDRS})
    else()
        # 如果没有对应的 .proto 文件，仅构建源文件
        add_executable(${EXECUTABLE_NAME} ${CPP_FILE})
    endif()

    # 链接库和头文件目录
    target_include_directories(${EXECUTABLE_NAME} PRIVATE ${INCLUDE_DIR})
    # 如果 protobuf 库需要链接（如果你使用了 protobuf 库）
    target_link_libraries(${EXECUTABLE_NAME} ${Protobuf_LIBRARIES})
endforeach()

# 添加清理目标
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROTOBUF_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -P clean-all.cmake
)
