#ifndef IRULAN_APP_H
#define IRULAN_APP_H

#include "irulan/math/Vector2.h"
#include "SDL2/SDL.h"
#include <string>

namespace iru {
    class App {
    public:
        App(Vector2i size, const std::string& title);

    private:
        std::string title;
        Vector2i size;
        bool done = false;
        SDL_Window* window;
        SDL_GLContext context;

        void constructWindow();

        void loop();
        void close(){done = true;};
        virtual bool init() = 0;
        virtual bool logic(float delta) = 0;
        virtual bool render(float delta) = 0;
    };
}

#endif //IRULAN_APP_H
