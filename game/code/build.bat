@echo off

set SDLlib=.\lib\SDL2_lib\

mkdir ..\..\build
pushd ..\..\build
cl /nologo /EHsc /Zi /MP ..\game\code\src\main.cpp ..\game\code\src\Entity.cpp ..\game\code\src\Player.cpp ..\game\code\src\Texture.cpp ..\game\code\src\WindowRenderer.cpp ..\game\code\src\TestMap.cpp ..\game\code\src\Timer.cpp "%SDLlib%SDL2.lib" "%SDLlib%SDL2main.lib"
popd