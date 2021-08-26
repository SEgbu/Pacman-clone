#include "../include/local/Score.hpp"

Score::Score(){
    mScore = 0;
    mScoreTextColor = {255, 255, 255, 255};
    mScoreFont = TTF_OpenFont("fonts/emulogic.ttf", 30);
    if (mScoreFont == nullptr){
        std::cerr << "Score font couldn't load: " << TTF_GetError() << std::endl;
    }
}

int Score::GetScore(){
    return mScore;
}

void Score::SetScore(int score){
    mScore += score;
}

void Score::Render(int x, int y, SDL_Renderer* renderer){
    if (!mScoreTextTexture.LoadFromRenderedText(std::to_string(mScore), mScoreTextColor, mScoreFont, renderer)){
        std::cerr << "Failed to load rendered text" << std::endl;
    }

    mScoreTextTexture.Render(x, y, renderer);
}

Score::~Score(){
    if (mScoreTextTexture.GetTexture() != nullptr){
        mScoreTextTexture.Free();
        TTF_CloseFont(mScoreFont);
    }
}