#include "../include/local/Entity.hpp"

Entity::Entity(){
    mPosX = 0;
    mPosY = 0;
}

float Entity::GetX(){
    return mPosX;
}

float Entity::GetY(){
    return mPosY;
}

SDL_Renderer* Entity::GetRenderer(){
    return mRenderer;
}

void Entity::SetX(int pPosX){
    mPosX = pPosX;
}

void Entity::SetY(int pPosY){
    mPosY = pPosY;
}

void Entity::SetRenderer(SDL_Renderer* pRenderer){
    mRenderer = pRenderer;
}