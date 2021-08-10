#include "../include/local/Player.hpp"

Player::Player(int x, int y, SDL_Renderer* renderer){
    SetX(x);
    SetY(y);
    mColliderRect = {GetX(), GetY(), PLAYER_WIDTH, PLAYER_HEIGHT};
    mVelX = 0;
    mVelY = 0;
    SetRenderer(renderer);
    if (!mTexture.LoadFromFile("images/pacman_01.png", GetRenderer())){
        std::cerr << "Could not load pacman_01.png" << std::endl;
    }
}

void Player::HandleEvents(SDL_Event& e){
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0){
        if (e.key.keysym.sym == SDLK_d){
            mVelX += PLAYER_VEL;
            mVelY = 0;
            if (mVelX > PLAYER_VEL){
                mVelX = PLAYER_VEL;
            }
            if (mVelX == 0){
                mVelX = PLAYER_VEL;
            }
        }
        if (e.key.keysym.sym == SDLK_a){
            mVelX -= PLAYER_VEL;
            mVelY = 0;
            if (mVelX < -PLAYER_VEL){
                mVelX = -PLAYER_VEL;
            }
            if (mVelX == 0){
                mVelX = -PLAYER_VEL;
            }
        }
        if (e.key.keysym.sym == SDLK_LEFT){ 
            mVelX -= PLAYER_VEL;
            mVelY = 0;
            if (mVelX < -PLAYER_VEL){
                mVelX = -PLAYER_VEL;
            }
            if (mVelX == 0){
                mVelX = -PLAYER_VEL;
            }
        }
        if (e.key.keysym.sym == SDLK_RIGHT){
            mVelX += PLAYER_VEL;
            mVelY = 0;
            if (mVelX > PLAYER_VEL){
                mVelX = PLAYER_VEL;
            }
            if (mVelX == 0){
                mVelX = PLAYER_VEL;
            }
        }
        if (e.key.keysym.sym == SDLK_s){
            mVelY += PLAYER_VEL;
            mVelX = 0;
            if (mVelY > PLAYER_VEL){
                mVelY = PLAYER_VEL;
            }
            if (mVelY == 0){
                mVelY = PLAYER_VEL;
            }
        }
        if (e.key.keysym.sym == SDLK_w){
            mVelY -= PLAYER_VEL;
            mVelX = 0;
            if (mVelY < -PLAYER_VEL){
                mVelY = -PLAYER_VEL;
            }
            if (mVelY == 0){
                mVelY = -PLAYER_VEL;
            }
        }
        if (e.key.keysym.sym == SDLK_DOWN){
            mVelY += PLAYER_VEL;
            mVelX = 0;
            if (mVelY > PLAYER_VEL){
                mVelY = PLAYER_VEL;
            }
            if (mVelY == 0){
                mVelY = PLAYER_VEL;
            }
        }
        if (e.key.keysym.sym == SDLK_UP){
            mVelY -= PLAYER_VEL;
            mVelX = 0;
            if (mVelY < -PLAYER_VEL){
                mVelY = -PLAYER_VEL;
            }
            if (mVelY == 0){
                mVelY = -PLAYER_VEL;
            }
        }

        std::cout << "mVelX: " << mVelX << std::endl;
        std::cout << "mVelY: " << mVelY << std::endl;
    }
}

void Player::Move(int screenWidth, int screenHeight, float timeStep){
    SetX(GetX() + (mVelX * timeStep));
    mColliderRect.x = GetX();
    
    if (GetX() < 0){
        SetX(0);
        mColliderRect.x = GetX();
    }
    else if (GetX() + PLAYER_WIDTH > screenWidth){
        SetX(screenWidth - PLAYER_WIDTH);
        mColliderRect.x = GetX();
    }

    SetY(GetY() + (mVelY * timeStep));
    mColliderRect.y = GetY();

    if (GetY() < 0){
        SetY(0);
        mColliderRect.y = GetY();
    }
    else if (GetY() + PLAYER_HEIGHT > screenHeight){
        SetY(screenHeight - PLAYER_HEIGHT);
        mColliderRect.y = GetY();
    }
}

void Player::Render(){
    if (mVelX > 0){
        mTexture.Render((int)GetX(), (int)GetY(), GetRenderer(), nullptr, 0.0f);
    }
    else if (mVelX < 0){
        mTexture.Render((int)GetX(), (int)GetY(), GetRenderer(), nullptr, 0.0f, nullptr, SDL_FLIP_HORIZONTAL);
    }
    else if (mVelY > 0){
        mTexture.Render((int)GetX(), (int)GetY(), GetRenderer(), nullptr, 90.0f);
    }
    else if (mVelY < 0){
        mTexture.Render((int)GetX(), (int)GetY(), GetRenderer(), nullptr, 270.0f);
    }
    else {
        mTexture.Render((int)GetX(), (int)GetY(), GetRenderer(), nullptr, 0.0f);
    }
}