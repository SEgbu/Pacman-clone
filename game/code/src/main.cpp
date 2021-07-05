#include <iostream>

#define SDL_MAIN_HANDLED
#define SDL_S
#define WINREN_S
#define TEX_S
#include "../include/local/Headers.hpp"

// Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Functions
bool Init();
bool LoadMedia(SDL_Renderer* pRenderer);
void Close();

// Global variables
Texture gImageTexture;

int main(int argv, char** args){
    WindowRenderer display("Pacman clone", SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!Init()){
        std::cerr << "Initialization function doesn't work" << std::endl;
    }
    else {
        if (!LoadMedia(display.renderer)){
            std::cerr << "Loading Media function doesn't work" << std::endl;
        }
    }

    // Runtime variables
    bool quit = false;
    SDL_Event e;

    while (!quit){
        if (SDL_PollEvent(&e) != 0){
            switch (e.type){
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }

        // Clear the previous frame with the render colour
        SDL_SetRenderDrawColor(display.renderer, 0, 0, 0, 255);
        SDL_RenderClear(display.renderer);

        // Render the image
        gImageTexture.Render((SCREEN_WIDTH - gImageTexture.GetWidth()) / 2, (SCREEN_HEIGHT - gImageTexture.GetHeight()) / 2, display.renderer);

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

    return success;
}

bool LoadMedia(SDL_Renderer* pRenderer){
    bool success = true;

    if (!gImageTexture.LoadFromFile("images/pacman_01.png", pRenderer)){
        std::cerr << "Pacman_01.png failed to load" << std::endl;
        success = false;
    }

    return success;
}

void Close(){
    gImageTexture.Free();
    SDL_Quit();
}