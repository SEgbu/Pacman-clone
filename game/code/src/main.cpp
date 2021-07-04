#include <iostream>

#define SDL_MAIN_HANDLED
#define SDL_S
#define WINREN_S
#include "../headers/local/Headers.hpp"

// Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Functions
bool Init();
bool LoadMedia();
void Close();

int main(int argv, char** args){
    WindowRenderer display("Pacman clone", SCREEN_WIDTH, SCREEN_HEIGHT);


    if (!Init()){
        std::cerr << "Initialization function doesn't work" << std::endl;
    }
    else {
        if (!LoadMedia()){
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

bool LoadMedia(){
    bool success = true;

    return success;
}

void Close(){

    SDL_Quit();
}