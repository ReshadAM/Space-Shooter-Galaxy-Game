#pragma once
#include <SDL_mixer.h>
#include <vector>
#include <string.h>

/**
 * This Music class defines the music object and provides functions that can store and play 
 * audio files. This class is specifically made for audio files larger than 10 seconds.
 * 
 *\author Reshad Mohsini (rmoshini)
 */

class Music {

public:
	/**
	* Music - initializes SDL_INIT_AUDIO,
	* The constructor calls the Mix_OpenAudio function,
	* from the SDL_mixer library with the appropriate, 
	* parameters, and checks if executed successfully.
	*/
	Music();


	/**
	 * ~Music - destructor deactivates SDL when program ends.
	*/
	~Music();


	/**
	* addMusic - Adds music files to the musicLibrary vector if Mix_OpenAudio initialize's the audio file.
	* \param sound_Effect_Path pointer for path of file.
	*/
	void addMusic(const char* sound_Effect_Path);


	/**
	* playMusic - Plays the requested music file stored in soundLibrary.
	* \param sound int value to represent index location of audio file.
	* \param num_loops int value to represent number of loops to play the audio.
	*/
	void playMusic(const int sound, int num_loops) const;

private:

	std::vector<Mix_Music*> musicLibrary;	/**< vector of type Mix_Music from the SDL_mixer library designed for files larger than 10s. */


};
