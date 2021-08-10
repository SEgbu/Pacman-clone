#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Timer.hpp"
#include "Entity.hpp"
#include "Texture.hpp"
#include <iostream>

class Player : public Entity{
    public:
        static const int PLAYER_VEL = 160;
        static const int PLAYER_WIDTH = 16;
        static const int PLAYER_HEIGHT = 16;

        Player(int x, int y, SDL_Renderer* renderer);
        void HandleEvents(SDL_Event& e);
        void Move(int screenWidth, int screenHeight, float timeStep);
        void Render();
    private:
        Texture mTexture;
        SDL_FRect mColliderRect;
        int mVelX, mVelY;
};                          

#endif