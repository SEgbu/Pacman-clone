#include "../include/local/WindowRenderer.hpp"


WindowRenderer::WindowRenderer(const char* p_title, int p_width, int p_height){
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_width, p_height, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cerr << "Window couldn't initialize, SDL error function: " << SDL_GetError() << std::endl;
    }
    else {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr){
            std::cerr << "Renderer couldn't initialize, SDL error function: " << SDL_GetError() << std::endl;
        }  
    }
}

WindowRenderer::~WindowRenderer(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;    
}