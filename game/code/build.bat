@echo off

set SDLlib=.\lib\SDL2_lib\

mkdir ..\..\build
pushd ..\..\build
cl /nologo /EHsc /Zi /MP ..\game\code\src\main.cpp ..\game\code\src\Entity.cpp ..\game\code\src\Player.cpp ..\game\code\src\Texture.cpp ..\game\code\src\WindowRenderer.cpp ..\game\code\src\TestMap.cpp ..\game\code\src\Timer.cpp ..\game\code\src\Music.cpp ..\game\code\src\Sound.cpp ..\game\code\src\Dot.cpp ..\game\code\src\Score.cpp "%SDLlib%SDL2.lib" "%SDLlib%SDL2main.lib" "%SDLlib%SDL2_mixer.lib" "%SDLlib%SDL2_ttf.lib"
popd