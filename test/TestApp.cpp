#include "TestApp.h"

bool TestApp::init() {
    iru::Buffer* buff = newBuffer(123);

    return true;
}

bool TestApp::logic(float delta) {
    return true;
}

bool TestApp::render(float delta) {
    return true;
}
