cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME test)

project(${PROJECT_NAME}
  LANGUAGES CXX
)

set(Kokkos_ENABLE_AGGRESSIVE_VECTORIZATION ON CACHE BOOL "Kokkos aggressive vectorization")
set(Kokkos_ENABLE_COMPILER_WARNINGS OFF CACHE BOOL "Kokkos compiler warnings")
set(Kokkos_ENABLE_DEBUG OFF CACHE BOOL "Kokkos debug")
set(Kokkos_ENABLE_DEBUG_BOUNDS_CHECK OFF CACHE BOOL "Kokkos debug bounds check")
set(CMAKE_BUILD_TYPE Release CACHE STRING "CMake build type")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")

set(Kokkos_ENABLE_CUDA ON CACHE BOOL "Enable CUDA")
set(Kokkos_ENABLE_CUDA_LAMBDA ON CACHE BOOL "Enable CUDA lambda")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern/kokkos extern/kokkos)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/extern/)
link_libraries(Kokkos::kokkos)

add_executable(${PROJECT_NAME}.xc main.cpp)
