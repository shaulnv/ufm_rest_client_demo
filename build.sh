rm -rf build
conan install . --build=missing
cmake --preset conan-release
cmake --build build/Release
cmake --install build/Release/ --prefix .