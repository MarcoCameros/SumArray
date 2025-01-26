cmake_minimum_required(VERSION 3.30)
project(SumArrays)

include_directories(/opt/homebrew/opt/libomp/include)
link_directories(/opt/homebrew/opt/libomp/lib)
# Configura el estándar de C++ (usa c++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Agrega las banderas adicionales necesarias (por ejemplo, -fopenmp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

# Define los archivos fuente
set(SOURCE_FILES main.cpp)

# Agrega el ejecutable
add_executable(SumArrays ${SOURCE_FILES})