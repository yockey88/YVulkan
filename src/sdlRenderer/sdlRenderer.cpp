#include "sdlRenderer/sdlRenderer.hpp"

namespace machy {
namespace core {

    void SDLWindow::Clear() {
        SDL_SetRenderDrawColor(mRenderer , 0 , 0 , 0 , 255);
        SDL_RenderClear(mRenderer);

        return;
    }

    void SDLWindow::HandleEvents(SDL_Event& e) {

        switch (e.type) {
            case SDL_KEYDOWN: 
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE: open = false; break;

                    default: break;
                }
            break;

            case SDL_WINDOWEVENT:
                switch (e.window.event) {
                    case SDL_WINDOWEVENT_CLOSE: open = false; break;

                    default: break;
                }
            break;

            default: break;
        }

        return;
    }

    bool SDLWindow::Create() {

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
            return false;
        
        mWindow = SDL_CreateWindow("Machy V{1.0.0}" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 1420 , 1020 , SDL_WINDOW_RESIZABLE);
        if (mWindow == nullptr) 
            return false;

        mRenderer = SDL_CreateRenderer(mWindow , -1 , SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
        if (mRenderer == nullptr)
            return false;

        open = true;

        return true;
    }

    void SDLWindow::FlushEvents() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            HandleEvents(event);
        }

        return;
    }

    void SDLWindow::BeginRender() {

        Clear();

        return;
    }

    void SDLWindow::EndRender() {

        SDL_RenderPresent(mRenderer);

        return;
    }

    void SDLWindow::Shutdown() {

        if (mRenderer != nullptr)
            SDL_DestroyRenderer(mRenderer);
        
        if (mWindow != nullptr)
            SDL_DestroyWindow(mWindow);
        
        SDL_Quit();

        return;
    }

}
}