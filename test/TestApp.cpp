#include "TestApp.h"

bool TestApp::init() {
    buff1 = defaultAllocator().newBuffer(123);
    desc1 = new iru::Descriptor();

    float vers1[] = {
            0.0, 0.5,
            0.5, 0.0,
            -0.5, 0.0,
    };

    std::string vers = "#version 450 core\n"
                       "layout (location = 0) in vec2 aPos;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
                       "}";

    std::string frags = "#version 450 core\n"
                        "out vec4 FragColor;\n"
                        "void main()\n"
                        "{\n"
                        "    FragColor = vec4(0, 1, 1,1);\n"
                        "} ";

    shad1 = new iru::Shader(vers, frags);

    buff1->setData(sizeof(float) * 6, 0, vers1);
    desc1->attachBuffer(buff1, 0, 0, sizeof(float)*2);
    desc1->setAttribute(0, 2, 0);
    desc1->setAttributeBuffer(0, 0);

    return true;
}

bool TestApp::logic(float delta) {
    return true;
}

bool TestApp::render(float delta) {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderer().setShader(shad1);
    renderer().setRenderTarget(nullptr);
    renderer().setDescriptor(desc1);
    renderer().draw(0, 3);
    flip();
}
