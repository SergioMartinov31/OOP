cmake_minimum_required(VERSION 3.10)
project(homeWork1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Библиотека
add_library(${PROJECT_NAME}_lib src/allNumbers.cpp)
set_target_properties(${PROJECT_NAME}_lib PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

# Исполняемый файл
add_executable(${PROJECT_NAME}_exe main.cpp)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)
set_target_properties(${PROJECT_NAME}_exe PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)



# Тесты
enable_testing()
add_executable(tests test/tests01.cpp)
target_link_libraries(tests PRIVATE ${PROJECT_NAME}_lib gtest_main)
set_target_properties(tests PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
add_test(NAME MyProjectTests COMMAND tests)
