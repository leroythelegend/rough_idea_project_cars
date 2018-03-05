#ifndef PCARS_DATA_VELOCITY_STATE_FORMAT_2_H_
#define PCARS_DATA_VELOCITY_STATE_FORMAT_2_H_

#include "datavelocitystate.h"
#include "packet.h"

namespace pcars {

class Data_Velocity_State_Format_2 : public Data_Velocity_State {
public:
	Data_Velocity_State_Format_2(const Packet&);
	virtual ~Data_Velocity_State_Format_2() {}

	Vector_Float orientation() const override;
	Vector_Float local_velocity() const override;
	Vector_Float world_velocity() const override;
	Vector_Float angular_velocity() const override;
	Vector_Float local_acceleration() const override;
	Vector_Float world_acceleration() const override;
	Vector_Float extents_centre() const override;

private:
	Packet packet_;
};

}

#endif

