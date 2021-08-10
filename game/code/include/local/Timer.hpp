#ifndef TIMER_HPP
#define TIMER_HPP

#define SDL_H
#include "Headers.hpp"

class Timer { 
    public:
        // Initializor
        Timer();

        // Clock actions
        void Start();
        void Pause();
        void Play();
        void Stop();

        // Timer's time
        Uint32 GetTicks();

        // State Checkers
        bool IsStarted();
        bool IsPaused();
    private:
        Uint32 mStartedTicks;
        Uint32 mPausedTicks;
        bool mStarted;
        bool mPaused;
};

#endif /* TIMER_HPP */