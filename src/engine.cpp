#include "engine.hpp"

namespace machy {

    Engine* Engine::instance = nullptr;

    Engine::Engine() {
        std::cout << "[[[CONSTRUCTING MACHY KERNEL]]]" << std::endl;
    }

    Engine& Engine::Instance() {
        if (instance == nullptr)
            instance = new Engine;
        return *instance;
    }

}