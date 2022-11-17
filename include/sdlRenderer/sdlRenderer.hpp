#ifndef SDL_RENDERER_HPP
#define SDL_RENDERER_HPP

#include <SDL.h>

namespace machy {
namespace core {

    struct sdlProps {
        int winH , winW;
    };

    class SDLWindow {

        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;

        int winH , winW;
        bool open;

        void Clear();
        void HandleEvents(SDL_Event& e);
        public:
            SDLWindow() : open(false) {}
            ~SDLWindow() { Shutdown(); }
    
            [[nodiscard]] bool Create();

            inline bool isOpen() const { return open; }
            void FlushEvents();
            void BeginRender();
            void EndRender();

            void Shutdown();    
    };

}
}

#endif