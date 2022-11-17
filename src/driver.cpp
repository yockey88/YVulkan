#include <vulkan/vulkan.h>
#include <SDL.h>
#undef main

#include "engine.hpp"
#include "glm/glm.hpp"

int main(int argc , char* argv[]) {
    machy::core::SDLWindow win;
    machy::core::sdlProps props;
    machy::util::parsers::CmndLineParser parser;

    parser.Read(argc , argv);
    parser.PrintOptions(); 
    
    if (parser.cmndOptionExists("-w"))
        props.winW = std::stoi(parser.getCmndOption("-w"));
    
    if (parser.cmndOptionExists("-h"))
        props.winW = std::stoi(parser.getCmndOption("-h"));
    
    if (!win.Create())
        return -1;
    
    while (win.isOpen()) {
        win.FlushEvents();
        win.BeginRender();
        win.EndRender();
    }
    
    return 0;
}

/*
    }*/