#ifndef IRULAN_DEBUG_H
#define IRULAN_DEBUG_H


#include "glad/glad.h"
namespace iru::ogl {
    const char *getErrorString(GLenum t_type);
    void APIENTRY openglCallbackFunction(
            GLenum t_source,
            GLenum t_type,
            GLuint t_id,
            GLenum t_severity,
            GLsizei t_length,
            const GLchar* t_message,
            const void* t_userParam
    );
}

#endif //IRULAN_DEBUG_H
