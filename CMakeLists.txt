cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Hello)

file(GLOB_RECURSE Source "Source/*.cpp" "Source/*.h")
add_subdirectory(Dependencies)

add_executable(Hello "Source/Main.cpp" ${Source})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(${PROJECT_NAME} PUBLIC Dependencies)