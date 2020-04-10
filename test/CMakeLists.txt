cmake_minimum_required(VERSION 3.14)
project(irulan_test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../build)

include_directories(../inc)
include_directories(${PROJECT_SOURCE_DIR})
link_directories(../lib)

add_executable(irulan_test main.cpp TestApp.cpp)
set_target_properties(irulan PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../build)
target_link_libraries(irulan_test ${PROJECT_SOURCE_DIR}/../build/libirulan.a)
target_link_libraries(irulan_test -lmingw32 -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive)



