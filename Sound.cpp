#include <FlameSteelBattleHorn/Sound.h>
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

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

	chunk = Mix_LoadWAV(path->c_str());

	if (chunk == nullptr) {
		cout << "Can't load sound " << Mix_GetError() << endl;
		throw runtime_error("Can't load sound");
	}

#endif
}

void Sound::play() {

#ifndef __EMSCRIPTEN__
	if (chunk) {
		if (Mix_PlayChannel(-1, chunk, 0)==-1) {
			printf("Mix_PlayChannel: %s\n",Mix_GetError());
		}		
	}
#else
	EM_ASM({
		var audio = new Audio('data/com.demensdeum.deathmask.beep.ogg');
		audio.play();
	});	
#endif
}

void Sound::stop() {

}

Sound::~Sound() {
#ifndef __EMSCRIPTEN__
	if (chunk) {
		Mix_FreeChunk(chunk);
	}
#endif
}