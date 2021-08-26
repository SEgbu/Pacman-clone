#ifndef SOUND_HPP
#define SOUND_HPP

#include "../external/SDL2/SDL_mixer.h"
#include <iostream>

class Sound {
    public:
        Sound();
        // -1 for infinite loops
        void Play(int loops);
        bool LoadSound(std::string path);
        ~Sound();
    private:
        Mix_Chunk* mSound;
};

#endif