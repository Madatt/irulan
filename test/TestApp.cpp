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

    iru::Vertex vers2[] = {
            iru::Vertex(
                    iru::Vector3f(0.0f, 4.f, 0.f),
                    iru::Vector2f(0.5f, 1.0f)
            ),
            iru::Vertex(
                    iru::Vector3f(2.f, 0.0f, 0.0f),
                    iru::Vector2f(1.0f, 0.0f)
            ),
            iru::Vertex(
                    iru::Vector3f(0.0f, 0.0f, 0.0f),
                    iru::Vector2f(0.0, 0.0)
            )
    };

    std::string vers = "#version 450 core\n"
                       "layout (location = 0) in vec3 i_Pos;\n"
                       "layout (location = 1) in vec2 i_Tex;\n"
                       "uniform mat4 u_Mat;\n"
                       "out vec2 o_Tex;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = u_Mat * vec4(i_Pos.x, i_Pos.y, i_Pos.z, 1.0);\n"
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


    per = iru::Matrix4::createPerspective(45.f, 800.f/600.f, 0.1f, 100.0f);
    cam = iru::Matrix4::createLookAt(iru::Vector3(0.f, 5.f, 10.f), iru::Vector3(0.f, 0.f, 0.f), iru::Vector3(0.f, 1.f, 0.f));
    res = per * cam;

    shad1 = new iru::Shader(vers, frags);
    shad1->setInt("u_Tex", 0);
    shad1->setMatrix4("u_Mat", res);

    buff1->setData(sizeof(iru::Vertex) * 3, 0, vers2);
    desc1->attachBuffer(buff1, 0, 0, sizeof(iru::Vertex));
    desc1->setAttribute(0, 3, 0);
    desc1->setAttribute(1, 2, sizeof(iru::Vector3f));
    desc1->setAttributeBuffer(0, 0);
    desc1->setAttributeBuffer(1, 0);

    tex1 = new iru::Texture();
    tex1->loadPng("rafonix.png");

    mesh1.loadObj("test.obj");

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
