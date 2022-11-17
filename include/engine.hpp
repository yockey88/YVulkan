#ifndef KERNEL_HPP
#define KERNEL_HPP

#include "sdlRenderer/sdlRenderer.hpp"
#include "parsers/cmndLineParser.hpp"

#include <iostream>

namespace machy {

    class Engine {
        static Engine* instance;

        core::SDLWindow sdlWin;
        /*
            Window
                Gui
                Renderer -> vkRenderer && sdlRenderer
                Handle Events
            App
                Active scene
                App data
            Log Manager
        */

        Engine();

        Engine(const Engine&) = delete;
        void operator=(const Engine&) = delete;
        public:
            static Engine& Instance();

            void delKernel() { if (instance != nullptr) delete instance; }
    };

}

#endif