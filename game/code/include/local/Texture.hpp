#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "../external/SDL2/SDL.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_H
#include "Headers.hpp"

#include <iostream>

class Texture{
    public:
        Texture();
        bool LoadFromFile(std::string path, SDL_Renderer* pRenderer, bool isColourKey = false, std::uint_fast32_t r = 0, std::uint_fast32_t g = 0, std::uint_fast32_t b = 0);
        void Render(int x, int y, SDL_Renderer* pRenderer, SDL_Rect* clip = nullptr, double angle = 0.0f, 
                    SDL_Point* centre = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, double enlargement = 1.0f);
        void Free();
        int GetWidth();
        int GetHeight();
        ~Texture();
    private:
        int mWidth, mHeight;
        SDL_Texture* mTexture;
};

#endif