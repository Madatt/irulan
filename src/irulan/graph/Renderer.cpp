#include "irulan/graph/Renderer.h"
#include "glad/glad.h"

namespace iru {
    Renderer::Renderer() {

    }

    void Renderer::draw(int first, int count) {
        bindDescriptor();
        bindShader();
        glDrawArrays(GL_TRIANGLES, first, count);
    }

    void Renderer::setDescriptor(Descriptor* descriptor) {
        nextState.descriptor = descriptor;
    }

    void Renderer::setRenderTarget(RenderTarget* target) {
        nextState.target = target;
    }

    void Renderer::setShader(Shader* shader) {
        nextState.shader = shader;
    }

    void Renderer::bindShader() {
        if (nextState.shader != nullptr) {
            if (nextState.shader != lastState.shader) {
                glUseProgram(nextState.shader->ptr.get());
                lastState.shader = nextState.shader;
            }
        }
    }

    void Renderer::bindDescriptor() {
        if (nextState.descriptor != nullptr) {
            if (nextState.descriptor != lastState.descriptor) {
                glBindVertexArray(nextState.descriptor->ptr.get());
                lastState.descriptor = nextState.descriptor;
            }
        }
    }


    void Renderer::bindTarget() {
        if (nextState.target != lastState.target) {
            if (nextState.target == nullptr)
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
            else
                glBindFramebuffer(GL_FRAMEBUFFER, nextState.target->ptr.get());
            lastState.target = nextState.target;
        }
    }

}