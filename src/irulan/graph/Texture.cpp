#include "irulan/graph/Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glad/glad.h"

namespace iru {
    Texture::Texture() {

    }

    void Texture::loadPng(const std::string& path) {
        int channels;
        stbi_set_flip_vertically_on_load(true);
        auto* img = stbi_load(path.c_str(), &size.x, &size.y, &channels, STBI_rgb_alpha);

        glTextureStorage2D(ptr.get(), 1, GL_RGBA8, size.x, size.y);
        glTextureSubImage2D(ptr.get(), 0, 0, 0, size.x, size.y, GL_RGBA, GL_UNSIGNED_BYTE, img);
    }
}