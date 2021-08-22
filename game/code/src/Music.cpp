#include "../include/local/Music.hpp"

Music::Music(){
    mMusic = nullptr;
}

void Music::Play(int loops){
    if (Mix_PlayingMusic() == 0){
        if (Mix_PlayMusic(mMusic, loops) == -1){
            std::cerr << "Can't play music: " << Mix_GetError() << std::endl;
        }
    }
}

bool Music::LoadMusic(std::string path){
    bool success = true;

    mMusic = Mix_LoadMUS(path.c_str());
    if (mMusic == nullptr){
        std::cerr << "Music couldn't load: " << Mix_GetError() << std::endl;
        success = false;
    }

    return success;
}

Music::~Music(){
    if (mMusic != nullptr){
        mMusic = nullptr;
    }
}