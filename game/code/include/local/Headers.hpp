#ifndef HEADER_HPP
#define HEADER_HPP

    #ifdef SDL_H
        #include "../external/SDL2/SDL.h"
    #endif

    #ifdef SDL_S
        #include "../include/external/SDL2/SDL.h"
    #endif

    #ifdef STBI_H
        #include "../external/stb_image/stb_image.h"
    #endif

    #ifdef STBI_S
        #include "../include/external/stb_image/stb_image.h"
    #endif

    #ifdef WINREN_H
        #include "WindowRenderer.hpp"
    #endif

    #ifdef WINREN_S
        #include "../include/local/WindowRenderer.hpp"
    #endif

    #ifdef TEX_H
        #include "Texture.hpp"
    #endif

    #ifdef TEX_S
        #include "../include/local/Texture.hpp"
    #endif

#endif