#ifndef PCARS_DATA_DAMAGE_STATE_H_
#define PCARS_DATA_DAMAGE_STATE_H_

#include "consts.h"

namespace pcars {

class Data_Damage_State {
public:
	virtual ~Data_Damage_State() {}

	virtual Vector_UInt brake_damage() const = 0;
	virtual Vector_UInt suspension_damage() const = 0;
	virtual unsigned int aero_damage() const = 0;
	virtual unsigned int engine_damage() const = 0;

};

}

#endif

