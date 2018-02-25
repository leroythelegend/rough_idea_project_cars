#ifndef PCARS_DATA_CONTROL_STATE_H_
#define PCARS_DATA_CONTROL_STATE_H_

#include "consts.h"

namespace pcars {

class Data_Control_State {
public:
	virtual ~Data_Control_State() {}

	virtual unsigned int joy_pad_0() const = 0;
	virtual unsigned int  d_pad() const = 0;
};

}

#endif

