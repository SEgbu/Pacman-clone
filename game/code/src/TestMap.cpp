#include "../include/local/TestMap.hpp"

TestMap::TestMap(int x, int y, SDL_Renderer* renderer){
    SetX(x);
    SetY(y);
    SetRenderer(renderer);
    mColliderRect = {GetX(), GetY(), 227, 30};
    if (!mTexture.LoadFromFile("images/map.png", GetRenderer(), true)){
        std::cout << "mTexture couldn't load" << std::endl;
    }
}

SDL_Rect TestMap::GetCollider(){
    return mColliderRect;
}

void TestMap::Render(){
    mTexture.Render(GetX(), GetY(), GetRenderer());
}