git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git checkout v3.21.12  # 推荐稳定版
git submodule update --init --recursive

cd cmake
mkdir build_vs2015
cd build_vs2015

cmake .. -G "Visual Studio 14 2015" -DCMAKE_INSTALL_PREFIX=../../../protobuf_install -A x64
cmake --build . --config Release
cmake --build . --config Release --target INSTALL
