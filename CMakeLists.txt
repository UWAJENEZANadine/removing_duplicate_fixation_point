cmake_minimum_required(VERSION 3.0.0)
project(assignment VERSION 0.1.0 LANGUAGES C CXX)
find_package(PkgConfig REQUIRED)
file(GLOB_RECURSE src
"src/*.cpp"
"src/*/*.cpp"
)

include(CTest)
enable_testing()

add_executable(assignment ${src})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
target_link_libraries(assignment)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(EXECUTABLE_OUTPUT_PATH "../bin")
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)




