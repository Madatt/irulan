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

    int App::loop() {
        init();

        while (!done) {
            float ela = SDL_GetTicks() - ticks;
            ticks = SDL_GetTicks();
            accu += ela;
            while (accu >= 1000.f / 60.f) {
                for(auto &k : keyStates) {
                    lastKeyStates[k.first] = k.second;
                }
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT)
                        close();

                    if (event.type == SDL_KEYDOWN and !event.key.repeat) {
                        keyStates[event.key.keysym.scancode] = 1;
                    }
                    else if (event.type == SDL_KEYUP and !event.key.repeat) {
                        keyStates[event.key.keysym.scancode] = 0;
                    }

                }


                logic(1.f / 60.f);
                accu -= 1000.f / 60.f;
            }

            render(1000.f / ela);
        }

        return 0;
    }

    int App::getKeyState(Uint8 key) {
        return keyStates[key];
    }

    int App::getLastKeyState(Uint8 key) {
        return lastKeyStates[key];
    }

    void App::flip() {
        SDL_GL_SwapWindow(window);
    }
}