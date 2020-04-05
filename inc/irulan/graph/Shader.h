#ifndef IRULAN_SHADER_H
#define IRULAN_SHADER_H

#include "irulan/system/opengl/Pointer.h"
#include "irulan/math/Matrix4.h"
#include <string>

namespace iru {
    class Shader {
        friend class Renderer;
    public:
        Shader(const std::string& ver, const std::string& frag);

        void setMatrix4(const std::string& name, Matrix4 mat) const;
        void setInt(const std::string& name, int val) const;

        bool check();

    private:
        ogl::Pointer<ogl::Shader> ptr;
        unsigned int vId = 0;
        unsigned int fId = 0;

        void setVertex(const std::string& ver);
        void setFragment(const std::string& frag);
        void link();
    };
}

#endif //IRULAN_SHADER_H
