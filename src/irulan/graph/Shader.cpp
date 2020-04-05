#include "irulan/graph/Shader.h"
#include "glad/glad.h"
#include <iostream>

namespace iru {
    Shader::Shader(const std::string& ver, const std::string& frag) {
        setVertex(ver);
        setFragment(frag);
        link();
    }

    void Shader::setMatrix4(const std::string& name, Matrix4 mat) const {
        if (ptr.get())
            glProgramUniformMatrix4fv(ptr.get(), glGetUniformLocation(ptr.get(), name.c_str()), 1, false,
                                      mat.data);
    }

    void Shader::setInt(const std::string& name, int val) const {
        if (ptr.get())
            glProgramUniform1i(ptr.get(), glGetUniformLocation(ptr.get(), name.c_str()), val);
    }

    bool Shader::check() {
        return ptr.get();
    }

    void Shader::setVertex(const std::string& ver) {
        if (vId)
            return;

        const char* ver_c = ver.c_str();
        char msg[512];
        int succ;

        vId = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vId, 1, &ver_c, NULL);
        glCompileShader(vId);
        glGetShaderiv(vId, GL_COMPILE_STATUS, &succ);
        if (!succ) {
            glGetShaderInfoLog(vId, 512, NULL, msg);
            std::cout << "[Error] Vertex compilation failed: " << msg << std::endl;
            vId = 0;
        }
    }

    void Shader::setFragment(const std::string& frag) {
        if (fId)
            return;

        const char* frag_c = frag.c_str();
        char msg[512];
        int succ;

        fId = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fId, 1, &frag_c, NULL);
        glCompileShader(fId);
        glGetShaderiv(fId, GL_COMPILE_STATUS, &succ);
        if (!succ) {
            glGetShaderInfoLog(fId, 512, NULL, msg);
            std::cout << "[Error] Fragment compilation failed: " << msg << std::endl;
            fId = 0;
        }
    }

    void Shader::link() {
        char msg[512];
        int succ;

        if (!fId || !vId)
            return;

        glAttachShader(ptr.get(), vId);
        glAttachShader(ptr.get(), fId);
        glLinkProgram(ptr.get());

        glGetProgramiv(ptr.get(), GL_LINK_STATUS, &succ);
        if (!succ) {
            glGetProgramInfoLog(ptr.get(), 512, NULL, msg);
            std::cout << "[Error] Shader linking failed: " << msg << std::endl;
        }

        glDeleteShader(fId);
        glDeleteShader(vId);
    }
}