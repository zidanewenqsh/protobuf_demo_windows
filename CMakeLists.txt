cmake_minimum_required(VERSION 3.10)
project(ProtobufDemo)

# 设置 Protobuf 版本（可以通过命令行参数覆盖，例如：-DPROTOBUF_VERSION=3.21.12）
if(NOT DEFINED PROTOBUF_VERSION)
    set(PROTOBUF_VERSION "3.21.12" CACHE STRING "Protobuf version to use")
endif()
message(STATUS "Using Protobuf version: ${PROTOBUF_VERSION}")

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 使用静态运行时库
if(MSVC)
    # foreach(flag_var
    #     CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
    #     CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
    #     CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
    #     CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
    #     if(${flag_var} MATCHES "/MD")
    #         string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    #     endif()
    # endforeach()
    
    # 在Release模式下添加调试信息
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
endif()

# 直接指定 Protobuf 路径
set(PROTOBUF_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/protobuf-${PROTOBUF_VERSION}/include")
set(PROTOBUF_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/protobuf-${PROTOBUF_VERSION}/lib")
set(PROTOBUF_GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(PROTOBUF_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/demo")

# 检查 Protobuf 目录是否存在
if(NOT EXISTS ${PROTOBUF_INCLUDE_DIR})
    message(FATAL_ERROR "Protobuf include directory not found: ${PROTOBUF_INCLUDE_DIR}")
endif()

if(NOT EXISTS ${PROTOBUF_LIB_DIR})
    message(FATAL_ERROR "Protobuf library directory not found: ${PROTOBUF_LIB_DIR}")
endif()

# 输出路径信息
message(STATUS "Protobuf include dir: ${PROTOBUF_INCLUDE_DIR}")
message(STATUS "Protobuf library dir: ${PROTOBUF_LIB_DIR}")
message(STATUS "Protobuf generated dir: ${PROTOBUF_GENERATED_DIR}")
message(STATUS "Protobuf source dir: ${PROTOBUF_SRC_DIR}")

# 包含 Protobuf 头文件目录
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(${PROTOBUF_GENERATED_DIR})

# 设置MSVC特定选项的宏
macro(set_msvc_options target_name)
if(MSVC)
    # 禁用一些警告
        target_compile_options(${target_name} PRIVATE 
        /wd4251 # 'identifier' : class 'type' needs to have dll-interface
        /wd4996 # 'function': was declared deprecated
    )
endif()
endmacro()

# 创建可执行文件的宏
macro(add_proto_executable name)
    add_executable(${name}_demo 
        ${PROTOBUF_SRC_DIR}/${name}.cpp
        ${PROTOBUF_SRC_DIR}/${name}.pb.cc
        ${PROTOBUF_GENERATED_DIR}/${name}.pb.h
    )
    
    # 添加库搜索路径
    target_link_libraries(${name}_demo "${PROTOBUF_LIB_DIR}/libprotobuf.lib")
    
    # 设置MSVC特定选项
    set_msvc_options(${name}_demo)
endmacro()

# 添加五个可执行文件
add_proto_executable(addressbook)
add_proto_executable(contact)
add_proto_executable(item)
add_proto_executable(person)
add_proto_executable(phonebook) 