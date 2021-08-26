#ifndef TESTMAP_HPP
#define TESTMAP_HPP

#include "Entity.hpp"
#include "Texture.hpp"
#include <iostream>

class TestMap : public Entity { 
    public:
        TestMap(int x, int y, SDL_Renderer* renderer);
        SDL_Rect GetCollider();
        Texture GetTexture();
        void Render();
    private:
        Texture mTexture;
        SDL_Rect mColliderRect;   
};

#endif
