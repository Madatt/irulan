#include "TestApp.h"

bool TestApp::init() {
    buff1 = defaultAllocator().newBuffer(123);
    desc1 = new iru::Descriptor();

    float vers1[] = {
            0.0, 0.5,
            0.5, 0.0,
            -0.5, 0.0,

            0.5, 1.0,
            1.0, 0.0,
            0.0, 0.0,
    };

    std::string vers = "#version 450 core\n"
                       "layout (location = 0) in vec2 i_Pos;\n"
                       "layout (location = 1) in vec2 i_Tex;\n"
                       "out vec2 o_Tex;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = vec4(i_Pos.x, i_Pos.y, 0.0, 1.0);\n"
                       "    o_Tex = i_Tex;\n"
                       "}";

    std::string frags = "#version 450 core\n"
                        "in vec2 o_Tex;\n"
                        "out vec4 FragColor;\n"
                        "uniform sampler2D u_Tex;\n"
                        "void main()\n"
                        "{\n"
                        "    FragColor = vec4(1, 1, 1, 1) * texture(u_Tex, o_Tex);\n"
                        "} ";

    shad1 = new iru::Shader(vers, frags);
    shad1->setInt("u_Tex", 0);

    buff1->setData(sizeof(float) * 12, 0, vers1);
    desc1->attachBuffer(buff1, 0, 0, sizeof(float)*2);
    desc1->setAttribute(0, 2, 0);
    desc1->setAttribute(1, 2, sizeof(float) * 6);
    desc1->setAttributeBuffer(0, 0);
    desc1->setAttributeBuffer(1, 0);

    tex1 = new iru::Texture();
    tex1->loadPng("rafonix.png");

    return true;
}

bool TestApp::logic(float delta) {
    return true;
}

bool TestApp::render(float delta) {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderer().setShader(shad1);
    renderer().setTexture(tex1, 0);
    renderer().setRenderTarget(nullptr);
    renderer().setDescriptor(desc1);
    renderer().draw(0, 3);
    flip();
}
