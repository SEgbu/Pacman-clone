#ifndef SCORE_HPP
#define SCORE_HPP

#include "Entity.hpp"
#include <fstream>
#include <string>
#include <iostream>

class Score {
    public:
        Score();
        int GetScore();
        void SetScore(int score);
        void Render(int x, int y, SDL_Renderer* renderer);
        int GetScoreHeight();
        int GetScoreWidth();
        ~Score();
    private:
        int mScore;
        TTF_Font* mScoreFont;
        SDL_Color mScoreTextColor;
        Texture mScoreTextTexture;
};

#endif