@echo off 

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

SET spdlogpath="../../Extern/spdlog-1.11.0/include"
SET enttpath="../../Extern/entt-3.11.0/single_include"
SET imguipath1="../../Extern/imgui-1.89"
SET imguipath2="../../Extern/imgui-1.89/backends"
SET imguipath3="../../Extern/imgui-1.89/backends/vulkan"
SET imguipath4="../../Extern/imgui-1.89/misc/cpp"
SET sdlpath="../../Extern/SDL2-2.24.2/include"
SET sdllib="../../Extern/SDL2-2.24.2/lib/x64"

SET srcfiles=/Isrc /Isrc/sdlRenderer /Isrc/parsers
SET inclfiles=/Iinclude /Iinclude/sdlRenderer /Iinclude/parsers

SET includes=%srcfiles% %inclfiles% /I%VULKAN_SDK%/Include /I%sdlpath% /I%spdlog% /I%enttpath% /I%imguipath1% /I%imguipath2% /I%imguipath3% /I%imguipath4% 
SET links=/link /LIBPATH:%VULKAN_SDK%/Lib vulkan-1.lib /LIBPATH:%sdllib%/lib/x64 SDL2.lib SDL2main.lib
SET defines=/D MACHY_DEBUG

SET compfiles=src/driver.cpp src/engine.cpp src/sdlRenderer/sdlRenderer.cpp src/parsers/cmndLineParser.cpp

@echo "[[[BUILDING MACHY V{1.0.0}]]]"

cl /std:c++20 /EHsc %includes% %defines% %compfiles% -o build/machy.exe %links%