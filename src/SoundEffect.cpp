#include "SoundEffect.h"
#include <SDL.h>
#include <iostream>

// constructor 
SoundEffect::SoundEffect()
{
    // Initalize SDL_Init(SDL_INIT_AUDIO using SDL_Init from the SDL library 
    SDL_Init(SDL_INIT_AUDIO);

    // Default variables by SDL for Mix_OpenAudio
    int freakquency = 44100;
    int channel = 2;
    int buffer = 2048;
    // SDL library function to open audio
    int result = Mix_OpenAudio(freakquency, MIX_DEFAULT_FORMAT, channel, buffer);

    if (result != 0)
    {
        std::cout << "Failed to initialize  audio.\n";
        exit(-1);
    }
}

// destructor to deactivate SDL
SoundEffect::~SoundEffect()
{
    // SDL_Quit();
}

void SoundEffect::addSoundEffect(const char* sound_Effect_Path)
{
    int library_size = soundEffectLibrary.size();
    // load the wave for the sound_Effect_Path
    Mix_Chunk* music = Mix_LoadWAV(sound_Effect_Path);

    // if Mix_Music initalized correctly add the new sound to the library
    if (music != nullptr) {
        std::cout << sound_Effect_Path << " added to library at index: " << library_size << "\n";
        soundEffectLibrary.push_back(music);

    }

    else std::cout << "Failed to initialize  audio.\n";

}

void SoundEffect::playSoundEffect(const int sound, int num_loops) const {
    int library_size = soundEffectLibrary.size() - 1;

    // if the index provided is larger than the size of the vertex containing the soundsEffects then prompt the user 
    if (sound > library_size)
    {
        std::cout << "Sound does not exist.\n";
        return;
    }
    // Play the sound from the soundLibrary at index sound
    Mix_PlayChannel(-1, soundEffectLibrary[sound], num_loops - 1);

}
