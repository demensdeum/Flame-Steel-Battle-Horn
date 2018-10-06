#include <FlameSteelBattleHorn/Sound.h>
#include <iostream>

using namespace FlameSteelBattleHorn;

void Sound::initializeSoundSystem() {

#ifndef __EMSCRIPTEN__

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1 ) { 
		throw runtime_error("Can't initialize sound system");
	}

	int flags = MIX_INIT_OGG;
	int initted = Mix_Init(flags);

	cout << flags << endl;
	cout << initted << endl;

	if ((initted & flags) != flags) {
	    printf("Mix_Init: Failed to init required ogg and mod support!\n");
	    printf("Mix_Init: %s\n", Mix_GetError());
	    throw runtime_error("Can't initialize SDL_Mixer properly");
	}
	else {
		cout << "SDL_MIXER initialized correctly" << endl;
	}


#endif
}

Sound::Sound(shared_ptr<string> path) {

#ifndef __EMSCRIPTEN__

	music = Mix_LoadMUS(path->c_str());

	if (music == nullptr) {
		cout << "Can't load music " << Mix_GetError() << endl;
		throw runtime_error("Can't load music");
	}
	
#endif
}

void Sound::play() {

#ifndef __EMSCRIPTEN__
	if (chunk) {
		
	}

	if (music) {
		if (Mix_PlayMusic(music, -1) == -1) {
			throw runtime_error("Can't play music");
		}
	}
	else {
			throw runtime_error("Can't play music - music is null");
	}
#endif
}

void Sound::stop() {

}

Sound::~Sound() {
#ifndef __EMSCRIPTEN__
	if (music) {
		Mix_FreeMusic(music);
	}

	if (chunk) {
		Mix_FreeChunk(chunk);
	}
#endif
}