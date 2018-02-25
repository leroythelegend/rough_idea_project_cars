#ifndef PCARS_DATA_INPUT_STATE_H_
#define PCARS_DATA_INPUT_STATE_H_

#include "consts.h"

namespace pcars {

class Data_Input_State {
public:
	virtual ~Data_Input_State() {}

	virtual float unfiltered_throttle() const = 0;
	virtual float unfiltered_brake() const = 0;
	virtual float unfiltered_steering() const = 0;
	virtual float unfiltered_clutch() const = 0;
};

}

#endif

