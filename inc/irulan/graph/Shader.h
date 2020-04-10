#ifndef IRULAN_SHADER_H
#define IRULAN_SHADER_H

#include "irulan/system/opengl/Pointer.h"
#include "irulan/math/Matrix4.h"
#include "irulan/system/Resource.h"
#include <string>

namespace iru {
    class Shader : public Resource {
        friend class Renderer;
    public:
        Shader(){};
        Shader(const std::string& ver, const std::string& frag);

        void loadFromFiles(const std::string& pathVer, const std::string& pathFrag);

        void setMatrix4(const std::string& name, Matrix4 mat) const;
        void setInt(const std::string& name, int val) const;
        void setFloat(const std::string& name, float val) const;
        void setVector3f(const std::string& name, const Vector3f& vec) const;

        bool check();

        void setVertex(const std::string& ver);
        void setFragment(const std::string& frag);
        void link();

    private:
        ogl::Pointer<ogl::Shader> ptr;
        unsigned int vId = 0;
        unsigned int fId = 0;
    };
}

#endif //IRULAN_SHADER_H
