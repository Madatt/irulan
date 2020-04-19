#include "irulan/graph/Shader.h"
#include "glad/glad.h"
#include <iostream>
#include <fstream>

namespace iru {
    Shader::Shader(const std::string& ver, const std::string& frag) {
        setVertex(ver);
        setFragment(frag);
        link();
    }

    void Shader::loadFromFiles(const std::string& pathVer, const std::string& pathFrag) {
        std::ifstream ver(pathVer);
        std::string verStr((std::istreambuf_iterator<char>(ver)),
                           std::istreambuf_iterator<char>());

        std::ifstream frag(pathFrag);
        std::string fragStr((std::istreambuf_iterator<char>(frag)),
                            std::istreambuf_iterator<char>());

        setVertex(verStr);
        setFragment(fragStr);
        link();
    }

    void Shader::setMatrix4(const std::string& name, Matrix4 mat) const {
        if (ptr.get())
            glProgramUniformMatrix4fv(ptr.get(), glGetUniformLocation(ptr.get(), name.c_str()), 1, false,
                                      mat.data);
    }

    void Shader::setFloat(const std::string& name, float val) const {
        if (ptr.get())
            glProgramUniform1f(ptr.get(), glGetUniformLocation(ptr.get(), name.c_str()), val);
    }

    void Shader::setInt(const std::string& name, int val) const {
        if (ptr.get())
            glProgramUniform1i(ptr.get(), glGetUniformLocation(ptr.get(), name.c_str()), val);
    }

    void Shader::setVector3f(const std::string& name, const Vector3f& vec) const {
        float data[3] = {vec.x, vec.y, vec.z};

        if (ptr.get())
            glProgramUniform3fv(ptr.get(), glGetUniformLocation(ptr.get(), name.c_str()), 1, data);
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
            defaultLog() << "[Shader] Vertex compilation failed: " << msg << "\n";
            vId = 0;
            return;
        }
        defaultLog() << "[Shader] Vertex compilation done" << "\n";
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
            defaultLog() << "[Shader] Fragment compilation failed: " << msg << "\n";
            fId = 0;
            return;
        }
        defaultLog() << "[Shader] Fragment compilation done" << "\n";
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
            defaultLog() << "[Shader] Shader linking failed: " << msg << "\n";
            return;
        }
        defaultLog() << "[Shader] Shader linking done" << "\n";
        glDeleteShader(fId);
        glDeleteShader(vId);
    }
}