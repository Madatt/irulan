#ifndef IRULAN_TESTAPP_H
#define IRULAN_TESTAPP_H

#include "irulan/irulan.h"

class TestApp : public iru::App {
    bool init() override;
    bool logic(float delta) override;
    bool render(float delta) override;

    iru::Buffer* buff1;
    iru::Descriptor* desc1;
    iru::Shader* shad1;
    iru::Texture* tex1;
};


#endif //IRULAN_TESTAPP_H
