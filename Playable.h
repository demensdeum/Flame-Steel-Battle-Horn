#ifndef FSBH_SOUND_SYSTEM_PLAYABLE_H
#define FSBH_SOUND_SYSTEM_PLAYABLE_H

#include <stdexcept>

using namespace std;

namespace FlameSteelBattleHorn {
class Playable {

public:
	virtual void play() { throw logic_error("Call to not overriden method play, playable abstract class"); };
	virtual void stop() { throw logic_error("Call to not overriden method stop, playable abstract class"); };

};
};

#endif