#include <vulkan/vulkan.h>
#include <SDL.h>
#undef main

#include "kernel.hpp"

int main() {

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Machy";
    appInfo.pEngineName = "Machy Kernel";

    VkInstanceCreateInfo instanceInfo = {};
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pApplicationInfo = &appInfo;

    VkInstance instance;

    VkResult res = vkCreateInstance(&instanceInfo , 0 , &instance);
    if (res == VK_SUCCESS) {
        std::cout << "Successfully Created VkInstance" << std::endl;
    }

    auto& kernel = machy::Kernel::Instance();
    kernel.delKernel();

    return 0;
}