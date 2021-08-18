#include <iostream>

#define SDL_MAIN_HANDLED
#define SDL_S
#define WINREN_S
#define TEX_S
#define PLAYER_S
#define TESTMAP_S
#define MIX_S
#define TIMER_S
#include "../include/local/Headers.hpp"

// Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Functions
bool Init();
bool LoadMedia(SDL_Renderer* pRenderer, Mix_Music** music00);
void Close(Mix_Music* music00);

int main(int argv, char** args){
    WindowRenderer display("Pacman clone", SCREEN_WIDTH, SCREEN_HEIGHT);
    Mix_Music* ChillMusic = nullptr;

    if (!Init()){
        std::cerr << "Initialization function doesn't work" << std::endl;
    }
    else {
        if (!LoadMedia(display.renderer, &ChillMusic)){
            std::cerr << "Loading Media function doesn't work" << std::endl;
        }
    }

    // Runtime variables
    bool quit = false;
    SDL_Event e;
    Player pacman((SCREEN_WIDTH) / 2, (SCREEN_HEIGHT) / 2, display.renderer);
    TestMap map(((SCREEN_WIDTH) / 2) - 1, ((SCREEN_HEIGHT) / 2) - 1, display.renderer);
    Timer time;
    time.Start();
    Mix_PlayMusic(ChillMusic, 1);

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

        // Render things
        pacman.Render(IntTime, 2);
        map.Render();

        // Present what is rendered to screen
        SDL_RenderPresent(display.renderer);
    }

    Close(ChillMusic);
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

    return success;
}

bool LoadMedia(SDL_Renderer* pRenderer, Mix_Music** music00){
    bool success = true;

    *music00 = Mix_LoadMUS("audio/pacman_beginning.wav"); 
    if (*music00 == nullptr){
        std::cerr << "Failed to load ChillMusic.wav, Mix error function: " << Mix_GetError() << std::endl;
        success = false;
    }

    return success;
}

void Close(Mix_Music* music00){
    Mix_FreeMusic(music00);
    SDL_Quit();
    Mix_Quit();
}