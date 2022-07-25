#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Timer.hpp"
#include "Entity.hpp"
#include "Texture.hpp"
#include <iostream>
#include <vector>

class Player : public Entity{
    public:
        static const int PLAYER_VEL = 2;
        static const int PLAYER_WIDTH = 12;
        static const int PLAYER_HEIGHT = 12;

        Player(int x, int y, SDL_Renderer* renderer);
        void HandleEvents(SDL_Event& e);
        void Move(int screenWidth, int screenHeight, SDL_Rect otherCollider);
        void Render(int time, int secondsPerFrame);
        bool CheckCollision(SDL_Rect& b);
        SDL_Rect GetCollider();
        ~Player();
    private:
        Texture mTexture[2];
        SDL_Rect mColliderRect;
        int mVelX, mVelY;
};                          

#endif