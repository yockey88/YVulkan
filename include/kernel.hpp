#ifndef KERNEL_HPP
#define KERNEL_HPP

#include <iostream>

namespace machy {

    class Kernel {
        static Kernel* instance;

        Kernel();

        Kernel(const Kernel&) = delete;
        void operator=(const Kernel&) = delete;
        public:
            static Kernel& Instance();

            void delKernel() { if (instance != nullptr) delete instance; }
    };

}

#endif