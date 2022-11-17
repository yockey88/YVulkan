#ifndef VK_RENDERER_HPP
#define VK_RENDERER_HPP

#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_core.h>
#include <SDL.h>
#include <SDL_vulkan.h>
#include <glm/glm.hpp>
#include <iostream>

namespace machy {
namespace vulkan {

    

}
}

void vk_init() {
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
}

#endif