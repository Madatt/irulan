cmake_minimum_required(VERSION 3.14)
project(irulan)
set(CMAKE_CXX_STANDARD 17)
include_directories(inc)

set(HEADERS
        inc/irulan/math/Matrix4.h
        inc/irulan/math/Vector2.h
        inc/irulan/math/Vector3.h
        inc/irulan/data/Vertex.h
        inc/irulan/system/App.h
        inc/irulan/system/opengl/Pointer.h
        inc/irulan/system/opengl/Pointer.tpp
        inc/irulan/system/ResourceManager.h
        inc/irulan/system/ResourceManager.tpp
        )

set(SOURCES
        src/irulan/system/App.cpp
        src/irulan/system/opengl/Traits.cpp
        src/irulan/system/opengl/Debug.cpp
        src/irulan/system/BufferAllocator.cpp
        src/irulan/system/Buffer.cpp
        src/irulan/system/Log.cpp
        src/irulan/system/Resource.cpp
        src/irulan/math/Matrix4.cpp
        src/irulan/math/Quaternion.cpp
        src/irulan/math/Noise.cpp
        src/irulan/data/Mesh.cpp
        src/irulan/graph/Renderer.cpp
        src/irulan/graph/Framebuffer.cpp
        src/irulan/graph/Descriptor.cpp
        src/irulan/graph/Shader.cpp
        src/irulan/graph/Texture.cpp
        src/irulan/graph/Texture2D.cpp
        src/glad/glad.c
        )


add_library(irulan ${SOURCES} ${HEADERS})
target_compile_options(irulan PUBLIC -fno-exceptions)
set_target_properties(irulan PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
add_subdirectory(test)