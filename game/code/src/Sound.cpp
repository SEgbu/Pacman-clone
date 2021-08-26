#include "../include/local/Sound.hpp"

Sound::Sound(){
    mSound = nullptr;
}

void Sound::Play(int loops){
    Mix_PlayChannel(-1, mSound, loops);
}

bool Sound::LoadSound(std::string path){
    bool success = true;

    mSound = Mix_LoadWAV(path.c_str());
    if (mSound == nullptr){
        std::cerr << "Sound couldn't load: " << Mix_GetError() << std::endl;
        success = false;
    }

    return success;
}

Sound::~Sound(){
    if (mSound != nullptr){
        mSound = nullptr;
    }
}