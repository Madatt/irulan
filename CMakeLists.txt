cmake_minimum_required(VERSION 3.14)
project(irulan)
set(CMAKE_CXX_STANDARD 17)
include_directories(inc)

set(HEADERS
        inc/irulan/math/Matrix4.h
        inc/irulan/math/Vector2.h
        inc/irulan/system/App.h
        inc/irulan/system/opengl/oglPointer.h
        inc/irulan/system/opengl/oglPointer.tpp
        )

set(SOURCES
        src/irulan/system/App.cpp
        src/irulan/math/Matrix4.cpp
        )


add_library(irulan ${SOURCES} ${HEADERS})