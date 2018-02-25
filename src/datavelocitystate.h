#ifndef PCARS_DATA_VELOCITY_STATE_H_
#define PCARS_DATA_VELOCITY_STATE_H_

#include "consts.h"

namespace pcars {

class Data_Velocity_State {
public:
	virtual ~Data_Velocity_State() {}

	virtual Vector_Float orientation() const = 0;
	virtual Vector_Float local_velocity() const = 0;
	virtual Vector_Float world_velocity() const = 0;
	virtual Vector_Float angular_velocity() const = 0;
	virtual Vector_Float local_acceleration() const = 0;
	virtual Vector_Float world_acceleration() const = 0;
	virtual Vector_Float extents_centre() const = 0;
};

}

#endif

