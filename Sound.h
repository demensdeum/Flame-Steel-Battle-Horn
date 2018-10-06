#ifndef FSBH_SOUND_H_
#define FSBH_SOUND_H_

#include <memory>
#include <string>

#ifndef __EMSCRIPTEN__
#include <SDL2/SDL_mixer.h>
#endif

using namespace std;

namespace FlameSteelBattleHorn {

class Sound {

public:
	static void initializeSoundSystem();
	Sound(shared_ptr<string> path);
	void play();
	void stop();
	~Sound();

private:
#ifndef __EMSCRIPTEN__
	Mix_Music *music = nullptr;
	Mix_Chunk *chunk = nullptr;
#endif

};

}

#endif