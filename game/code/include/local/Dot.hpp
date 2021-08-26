#ifndef DOT_HPP
#define DOT_HPP

#include "Entity.hpp"
#include "Sound.hpp"
#include "Score.hpp"
#include <vector>

class Dot : public Entity {
    public:
        Dot(int x, int y, SDL_Renderer* renderer);
        void Render();
        bool OnDotCollision(SDL_Rect&otherCollider);
        bool CheckCollision(SDL_Rect& b);
        int GetDotScore();
        ~Dot();
    private:
        SDL_Rect mColliderRect;    
        Texture mTexture;
        Sound mSound;
        Score mScore;
        bool mUpdateScore;
        bool mCollided;
        int mCheckedCollision;
};

#endif