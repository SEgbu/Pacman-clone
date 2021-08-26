#include "../include/local/Dot.hpp"

Dot::Dot(int x, int y, SDL_Renderer *renderer){
    SetX(x); 
    SetY(y);
    SetRenderer(renderer);
    mScore.SetScore(10);
    if (!mSound.LoadSound("audio/pacman_chomp.wav")){
        std::cerr << "Failed to load pacman_chomp.wav" << std::endl;
    }
    if (!mTexture.LoadFromFile("images/dot.png", GetRenderer())){
        std::cerr << "Failed to load dot.png" << std::endl;
    }
    mColliderRect = {GetX(), GetY(), mTexture.GetWidth(), mTexture.GetHeight()};
    mCheckedCollision = 1;
}

void Dot::Render(){
    mTexture.Render(GetX(), GetY(), GetRenderer());
}

bool Dot::OnDotCollision(SDL_Rect& otherCollider){
    mCollided = false;

    if (CheckCollision(otherCollider) && mCheckedCollision > 0){
        mTexture.NullTexture(true);
        mSound.Play(0);
        mCheckedCollision--;
        mCollided = true;
    }

    return mCollided;
}

bool Dot::CheckCollision(SDL_Rect& b){
    int topA, topB;
    int bottomA, bottomB;
    int leftA, leftB;
    int rightA, rightB;

    topA = mColliderRect.y;
    bottomA = mColliderRect.y + mColliderRect.h;
    leftA = mColliderRect.x;
    rightA = mColliderRect.x + mColliderRect.w;
    
    topB = b.y;
    bottomB = b.y + b.h;
    leftB = b.x;
    rightB = b.x + b.w;

    if (bottomA <= topB){
        return false;
    }
    
    if (bottomB <= topA){
        return false;
    }
    if (leftA >= rightB){
        return false;
    }
    
    if (rightA <= leftB){
        return false;
    }
    
    return true;
}

int Dot::GetDotScore(){
    return mScore.GetScore();
}

Dot::~Dot(){
    if (mTexture.GetTexture() != nullptr){
        mTexture.Free();
    }
}