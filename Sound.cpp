#include <FlameSteelBattleHorn/Sound.h>

using namespace FlameSteelGameToolkit::FlameSteelBattleHorn;

Sound::Sound(shared_ptr<string> path) {
#ifndef __EMSCRIPTEN__
	chunk = Mix_LoadWAV(path->c_str());
#endif
}

void Sound::play() {
#ifndef __EMSCRIPTEN__
	if (chunk) {
		
	}

	if (music) {
		
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