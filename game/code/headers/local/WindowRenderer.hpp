#ifndef WINDOW_HPP
#define WINDOW_HPP

#define SDL_H
#include "Headers.hpp"
#include <iostream>

class WindowRenderer{
    public:
        SDL_Renderer* renderer;
        SDL_Window* window;

        WindowRenderer(const char* p_title, int p_width, int p_height);
        ~WindowRenderer();
};

#endif