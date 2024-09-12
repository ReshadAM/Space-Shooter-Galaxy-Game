#pragma once
#include <SDL_mixer.h>
#include <vector>
#include <string.h>

/**
 * This SoundEffect class defines the SoundEffect object and provides functions that can store and play
 * audio files. This class is specifically made for audio files smaller than 10 seconds.
 *
 *\author Reshad Mohsini (rmoshini)
 */


class SoundEffect {
public:
	/**
	* SoundEffect - initializes SDL_INIT_AUDIO,
	* The constructor calls the Mix_OpenAudio function,
	* from the SDL_mixer library with the appropriate,
	* parameters, and checks if executed successfully.
	*/
	SoundEffect();
	
	/**
	 * ~SoundEffect - destructor deactivates SDL when program ends.
	*/
	~SoundEffect();

	/**
	* addSoundEffect - Adds audio files to the soundEffectLibrary vector if Mix_LoadWAV initialize's the audio file.
	* \param sound_Effect_Path pointer for path of file.
	*/
	void addSoundEffect(const char* sound_Effect_Path);


	/**
	* playSoundEffect - Plays the requested audio file stored in soundEffectLibrary.
	* \param sound int value to represent index location of audio file.
	* \param num_loops int value to represent number of loops to play the audio.
	*/
	void playSoundEffect(const int sound, int num_loops) const;

private:

	// Vector of type Mix_Music for audio more than 10 seconds to store music files 
	std::vector<Mix_Chunk*> soundEffectLibrary; /**< vector of type Mix_Chunk from the SDL_mixer library designed for files smaller than 10s. */


};
