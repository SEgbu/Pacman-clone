@echo off

set SDLlib=.\lib\SDL2_lib\

mkdir ..\..\build
pushd ..\..\build
cl /nologo /EHsc /Zi ..\game\code\src\*.cpp "%SDLlib%SDL2.lib" "%SDLlib%SDL2main.lib"
popd