# @file CMakeLists.txt
# 
# CMake files for lambda example

cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(Lambda)

# lambda
add_executable(lambda)
target_sources(lambda PRIVATE lambda.cpp Framework.cpp IncrementLength.cpp StringIncrementer.cpp)
target_compile_features(lambda PRIVATE cxx_std_17)
target_compile_options(lambda PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall>
)

# run
add_custom_target(run
        COMMENT "Run"
        COMMAND $<TARGET_FILE:lambda>
        DEPENDS lambda
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
