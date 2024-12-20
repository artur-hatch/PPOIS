cmake_minimum_required(VERSION 3.10)

project(SocialNetwork)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)

file(GLOB SOURCES
    src/source/*.cpp
)

add_library(utils src/utils/utils.cpp)

add_executable(SocialNetwork ${SOURCES} src/main.cpp)
target_include_directories(SocialNetwork PRIVATE src/headers lib)
target_link_libraries(SocialNetwork PRIVATE utils)

enable_testing()

file(GLOB TEST_SOURCES
    tests/*.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

add_executable(SocialNetworkTests ${TEST_SOURCES} ${SOURCES})
target_include_directories(SocialNetworkTests PRIVATE src/headers lib)
target_link_libraries(SocialNetworkTests PRIVATE utils gtest gtest_main)

add_test(NAME SocialNetworkTests COMMAND SocialNetworkTests)
