#ifndef IRULAN_TESTAPP_H
#define IRULAN_TESTAPP_H

#include "irulan/irulan.h"

class TestApp : public iru::App {
public:
    ~TestApp();

private:
    bool init() override;
    bool logic(float delta) override;
    bool render(float delta) override;

    iru::Buffer* buff1;
    iru::Descriptor* desc1;
    iru::Shader* shad1;
    iru::Texture2D* tex1;
    iru::Mesh mesh1;
    iru::Matrix4 cam, per, res;
    iru::Vector3f camPos;
    float verAn = 0.f;
    float horAn = 0.f;
};


#endif //IRULAN_TESTAPP_H
