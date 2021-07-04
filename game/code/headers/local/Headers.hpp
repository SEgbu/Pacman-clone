#ifndef HEADER_HPP
#define HEADER_HPP

    #ifdef SDL_H
        #include "../external/SDL2/SDL.h"
    #endif

    #ifdef SDL_S
        #include "../headers/external/SDL2/SDL.h"
    #endif

    #ifdef WINREN_H
        #include "WindowRenderer.hpp"
    #endif

    #ifdef WINREN_S
        #include "../headers/local/WindowRenderer.hpp"
    #endif

#endif