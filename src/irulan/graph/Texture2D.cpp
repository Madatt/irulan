#include "irulan/graph/Texture2D.h"
#include "irulan/system/Log.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glad/glad.h"

namespace iru {
    Texture2D::Texture2D() {

    }

    void Texture2D::loadPng(const std::string& path) {
        defaultLog << "[Texture2D] Loading texture from file: " << path << "\n";
        int channels;
        stbi_set_flip_vertically_on_load(true);
        auto* img = stbi_load(path.c_str(), &size.x, &size.y, &channels, STBI_rgb_alpha);
        defaultLog << "[Texture2D] Loaded texture: " << size.x << "x" << size.y << "\n";

        glTextureStorage2D(ptr.get(), 1, GL_RGBA8, size.x, size.y);
        glTextureSubImage2D(ptr.get(), 0, 0, 0, size.x, size.y, GL_RGBA, GL_UNSIGNED_BYTE, img);
        glTextureParameteri(ptr.get(), GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTextureParameteri(ptr.get(), GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }

    void Texture2D::createEmpty(const Vector2i& size) {
        this->size = size;
        glTextureStorage2D(ptr.get(), 1, GL_RGBA8, size.x, size.y);
        glTextureParameteri(ptr.get(), GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTextureParameteri(ptr.get(), GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        defaultLog << "[Texture2D] Created empty texture: " << size.x << "x" << size.y << "\n";

    }

    void Texture2D::createDepth(const Vector2i& size) {
        this->size = size;
        glTextureStorage2D(ptr.get(), 1, GL_DEPTH_COMPONENT24, size.x, size.y);
        glTextureParameteri(ptr.get(), GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTextureParameteri(ptr.get(), GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        defaultLog << "[Texture2D] Created depth texture: " << size.x << "x" << size.y << "\n";
    }
}