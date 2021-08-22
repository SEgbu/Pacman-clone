#ifndef MUSIC_HPP
#define MUSIC_HPP

#include "../external/SDL2/SDL_mixer.h"
#include <iostream>

class Music {
    public:
        Music();
        // -1 for infinite loops
        void Play(int loops);
        bool LoadMusic(std::string path);
        ~Music();
    private:
        Mix_Music* mMusic;
};

#endif