#include "../include/local/Timer.hpp"

Timer::Timer(){
    mStarted = false;
    mPaused = false;
    mStartedTicks = 0;
    mPausedTicks = 0;
}

void Timer::Start(){
    mStarted = true;
    mPaused = false;
    mStartedTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void Timer::Pause(){
    if (mStarted && !mPaused){
        mPaused = true;
        mPausedTicks = SDL_GetTicks() - mStartedTicks;
        mStartedTicks = 0; 
    }
}

void Timer::Play(){
    if (mStarted && mPaused){
        mPaused = false; 
        mStartedTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

void Timer::Stop(){
    if (mStarted){
        mStarted = false;
        mPaused = false;
        mStartedTicks = 0;
        mPausedTicks = 0;
    }
}

Uint32 Timer::GetTicks(){
    Uint32 time = 0;

    if (mStarted){
        if (mPaused){
            time = mPausedTicks;
        }
        else {
            time = SDL_GetTicks() - mStartedTicks;
        }
    }

    return time;
}

bool Timer::IsStarted(){
    return mStarted;
}

bool Timer::IsPaused(){
    return mPaused;
}