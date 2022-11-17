#include "kernel.hpp"

namespace machy {

    Kernel* Kernel::instance = nullptr;

    Kernel::Kernel() {
        std::cout << "[[[CONSTRUCTING MACHY KERNEL]]]" << std::endl;
    }

    Kernel& Kernel::Instance() {
        if (instance == nullptr)
            instance = new Kernel;
        return *instance;
    }

}