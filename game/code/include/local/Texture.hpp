#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#define SDL_H
#define STB_IMAGE_IMPLEMENTATION
#define STBI_H
#include "Headers.hpp"

#include <iostream>

class Texture{
    public:
        Texture();
        bool LoadFromFile(std::string path, SDL_Renderer* pRenderer);
        void Render(int x, int y, SDL_Renderer* pRenderer, SDL_Rect* clip = NULL, double enlargement = 1.0);
        void Free();
        int GetWidth();
        int GetHeight();
        ~Texture();
    private:
        int mWidth, mHeight;
        SDL_Texture* mTexture;
};

#endif