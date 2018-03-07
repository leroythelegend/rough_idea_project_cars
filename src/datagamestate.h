#ifndef PCARS_DATA_GAME_STATE_H_
#define PCARS_DATA_GAME_STATE_H_

#include "consts.h"

namespace pcars {

class Data_Game_State {
public:
	virtual ~Data_Game_State() {}

	virtual unsigned int session_state() const = 0;
	virtual unsigned int game_state() const = 0;
	virtual unsigned int race_state_flags() const = 0;
	virtual unsigned int pit_mode() const = 0;
};

}

#endif

