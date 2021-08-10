#ifndef ENTITY_HPP
#define ENTITY_HPP

#define TEX_H
#include "Headers.hpp"

class Entity{
    public:
        Entity();
        float GetX();
        float GetY();
        SDL_Renderer* GetRenderer();
        void SetX(int pPosX);
        void SetY(int pPosY);
        void SetRenderer(SDL_Renderer* pRenderer);
    private:
        int mPosX, mPosY;
        SDL_Renderer* mRenderer;
};

#endif