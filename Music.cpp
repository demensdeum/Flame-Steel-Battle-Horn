#include <FlameSteelBattleHorn/Music.h>
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

using namespace FlameSteelBattleHorn;

Music::Music(shared_ptr<string> path) {

#ifndef __EMSCRIPTEN__

	music = Mix_LoadMUS(path->c_str());

	if (music == nullptr) {
		cout << "Can't load music " << Mix_GetError() << endl;
		throw runtime_error("Can't load music");
	}
	
#else

	this->path = path;

#endif
}

void Music::play() {

#ifndef __EMSCRIPTEN__
	if (music) {
		if (Mix_PlayMusic(music, -1) == -1) {
			throw runtime_error("Can't play music");
		}
	}
	else {
			throw runtime_error("Can't play music - music is null");
	}
#else
	if (path.get() != nullptr) {

		cout << "play sound through javascript" << endl;

		EM_ASM_({

			var audioPath = Pointer_stringify($0);
			audioPath += ".mp3";

			var audio = new Audio(audioPath);
			audio.loop = true;
			audio.play();

		}, path->c_str());
	}
	else {
		cout << "can't play sound - path is null" << endl;
	}
#endif
}

void Music::stop() {

}

Music::~Music() {
#ifndef __EMSCRIPTEN__
	if (music) {
		Mix_FreeMusic(music);
	}
#endif
}