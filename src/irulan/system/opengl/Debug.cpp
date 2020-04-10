#include "irulan/system/opengl/Debug.h"
#include "irulan/system/Log.h"
#include "glad/glad.h"
#include <cstdio>
#include <cstdlib>

namespace iru::ogl {
    const char* getErrorString(GLenum t_type) {
        switch (t_type) {
            case GL_NO_ERROR:
                return "GL_NO_ERROR";
            case GL_INVALID_ENUM:
                return "GL_INVALID_ENUM";
            case GL_INVALID_VALUE:
                return "GL_INVALID_VALUE";
            case GL_INVALID_OPERATION:
                return "GL_INVALID_OPERATION";
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                return "GL_INVALID_FRAMEBUFFER_OPERATION";
            case GL_OUT_OF_MEMORY:
                return "GL_OUT_OF_MEMORY";
            case GL_STACK_UNDERFLOW:
                return "GL_STACK_UNDERFLOW"; // Until OpenGL 4.2
            case GL_STACK_OVERFLOW:
                return "GL_STACK_OVERFLOW"; // Until OpenGL 4.2
            default:
                return "invalid error number";
        }
    }

    void APIENTRY openglCallbackFunction(
            GLenum t_source,
            GLenum t_type,
            GLuint t_id,
            GLenum t_severity,
            GLsizei t_length,
            const GLchar* t_message,
            const void* t_userParam
    ) {
        (void) t_source;
        (void) t_type;
        (void) t_id;
        (void) t_severity;
        (void) t_length;
        (void) t_userParam;
        //fprintf(stderr, "%s\n", t_message);
        defaultLog << "[OpenGl] " << t_message << "\n";
        if (t_severity == GL_DEBUG_SEVERITY_HIGH) {
           // fprintf(stderr, "Aborting...\n");
            //abort();
        }
    }

}