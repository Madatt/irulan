#include <iostream>
#include "irulan/irulan.h"
#include "TestApp.h"

int main(int argc, char *argv[]) {
    std::cout << "TEST" << std::endl;

    TestApp test;
    test.construct(iru::Vector2i(800, 600), "test");
    return 0;
}