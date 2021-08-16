#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Timer.hpp"
#include "Entity.hpp"
#include "Texture.hpp"
#include <iostream>

class Player : public Entity{
    public:
        static const int PLAYER_VEL = 2;
        static const int PLAYER_WIDTH = 16;
        static const int PLAYER_HEIGHT = 16;

        Player(int x, int y, SDL_Renderer* renderer);
        void HandleEvents(SDL_Event& e);
        void Move(int screenWidth, int screenHeight, SDL_Rect otherCollider);
        void Render();
        bool CheckCollision(SDL_Rect& b);
    private:
        Texture mTexture;
        SDL_Rect mColliderRect;
        int mVelX, mVelY;
};                          

#endif