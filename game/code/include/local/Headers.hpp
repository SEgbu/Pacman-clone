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

    #ifdef MIX_H
        #include "../external/SDL2/SDL_mixer.h"
    #endif

    #ifdef MIX_S
        #include "../include/external/SDL2/SDL_mixer.h"
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

    #ifdef PLAYER_H
        #include "Player.hpp"
    #endif

    #ifdef PLAYER_S
        #include "../include/local/Player.hpp"
    #endif

    #ifdef ENTITY_H
        #include "Entity.hpp"
    #endif

    #ifdef ENTITY_S
        #include "../include/local/Entity.hpp"
    #endif

    #ifdef MUSIC_H
        #include "Music.hpp"
    #endif

    #ifdef MUSIC_S
        #include "../include/local/Music.hpp"
    #endif

    #ifdef TIMER_H
        #include "Timer.hpp"
    #endif

    #ifdef TIMER_S
        #include "../include/local/Timer.hpp"
    #endif

    #ifdef TESTMAP_H
        #include "TestMap.hpp"
    #endif

    #ifdef TESTMAP_S
        #include "../include/local/TestMap.hpp"
    #endif

    #ifdef DOT_S
        #include "../include/local/Dot.hpp"
    #endif

    #ifdef DOT_H
        #include "Dot.hpp"
    #endif

    #ifdef SCORE_S
        #include "../include/local/Score.hpp"
    #endif

    #ifdef SCORE_H
        #include "Score.hpp"
    #endif

#endif