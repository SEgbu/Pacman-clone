#include <iostream>

#define SDL_MAIN_HANDLED
#define SDL_S
#define WINREN_S
#define TEX_S
#define PLAYER_S
#define TESTMAP_S
#define MIX_S
#define MUSIC_S
#define TIMER_S
#define DOT_S
#define SCORE_S
#include "../include/local/Headers.hpp"
#include "../include/external/SDL2/SDL_ttf.h"

// Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Functions
bool Init();
bool LoadMedia(SDL_Renderer* pRenderer, Music& music);
void Close();

int main(int argv, char** args){
    WindowRenderer display("Pacman clone", SCREEN_WIDTH, SCREEN_HEIGHT);
    Music pacmanMusic;

    if (!Init()){
        std::cerr << "Initialization function doesn't work" << std::endl;
    }
    else {
    if (!LoadMedia(display.renderer, pacmanMusic)){
            std::cerr << "Loading Media function doesn't work" << std::endl;
        }
    }

    // Runtime variables
    bool quit = false;
    SDL_Event e;
    Player pacman((SCREEN_WIDTH) / 2, (SCREEN_HEIGHT) / 2, display.renderer);
    TestMap map(((SCREEN_WIDTH) / 2) - 1, ((SCREEN_HEIGHT) / 2) - 1, display.renderer);
    int DotX = map.GetX() + map.GetTexture().GetWidth() - 8;
    int DotY = map.GetY() + map.GetTexture().GetHeight() - 8;
    int Dot2X = DotX - 20;
    int Dot2Y = DotY;
    Timer time;
    Dot dot(DotX, DotY, display.renderer);
    Dot dot2(Dot2X, Dot2Y, display.renderer);
    Score score;
    time.Start();
    Mix_VolumeMusic(30);
    pacmanMusic.Play(1);

    while (!quit){
        if (SDL_PollEvent(&e) != 0){
            switch (e.type){
                case SDL_QUIT:
                    quit = true;
                break;
            }
                // Handle key inputs
                pacman.HandleEvents(e);
        }


        // Move pacman
        pacman.Move(SCREEN_WIDTH, SCREEN_HEIGHT, map.GetCollider());
        // Clear the prevaious frame with the render colour
        SDL_SetRenderDrawColor(display.renderer, 0, 0, 0, 255);
        SDL_RenderClear(display.renderer);

        int IntTime = static_cast<int>(time.GetTicks() / 1000.0f);

        // // Print score
        // std::cout << dot.GetDotScore() << std::endl;

        // If collided update score by 10
        if (dot.OnDotCollision(pacman.GetCollider()) || dot2.OnDotCollision(pacman.GetCollider())){
            score.SetScore(dot.GetDotScore());
        }

        // Render things
        score.Render(0, 0, display.renderer);
        map.Render();
        pacman.Render(IntTime, 2);
        dot.Render();
        dot2.Render();

        // Present what is rendered to screen
        SDL_RenderPresent(display.renderer);
    }

    Close();
    return 0;
}

bool Init(){
    bool success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cerr << "SDL couldn't initialize, SDL error function: " << SDL_GetError() << std::endl;
        success = false;
    }

    Mix_CloseAudio();
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to initialize SDL_Mixer, Mix error function: " << Mix_GetError() << std::endl;
        success = false;
    } 

    if (TTF_Init() < 0){
        std::cerr << "Failed to initialize SDL_TTF, TTF error function: " << TTF_GetError() << std::endl;
        success = false;
    }

    return success;
}

bool LoadMedia(SDL_Renderer* pRenderer, Music& music){
    bool success = true;

    if (!music.LoadMusic("audio/pacman_beginning.wav")){
        std::cerr << "Failed to load pacman_beginning.wav" << std::endl;
        success = false;
    }

    return success;
}

void Close(){
    SDL_Quit();
    Mix_Quit();
}