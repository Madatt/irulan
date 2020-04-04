#include <iostream>
#include "irulan/system/App.h"
#include "glad/glad.h"

namespace iru {
    int App::construct(Vector2i size, const std::string& title) {
        this->size = size;
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        constructWindow();
        if (!gladLoadGL()) {
            std::cout << "glad loading error" << std::endl;
            close();
            return 0;
        }

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glViewport(0, 0, size.x, size.y);
        return loop();
    }

    void App::constructWindow() {
        window = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  size.x, size.y,
                                  SDL_WINDOW_OPENGL);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
        context = SDL_GL_CreateContext(window);
        if (context == nullptr) {
            close();
        }
    }

    Buffer* App::newBuffer(unsigned int size) {
        return allc.alloc(size);
    }

    int App::loop() {
        init();

        while (!done) {
            float ela = SDL_GetTicks() - ticks;
            ticks = SDL_GetTicks();
            accu += ela;

            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT)
                    close();

            }

            while (accu >= 1000.f / 60.f) {
                logic(1.f / 60.f);
                accu -= 1000.f / 60.f;
            }
            glEnable(GL_DEPTH_TEST);
            render(1000.f / ela);
        }

        return 0;
    }
}