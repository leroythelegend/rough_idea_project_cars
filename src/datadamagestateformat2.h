#ifndef PCARS_DATA_DAMAGE_STATE_FORMAT_2_H_
#define PCARS_DATA_DAMAGE_STATE_FORMAT_2_H_

#include "datadamagestate.h"
#include "packet.h"

namespace pcars {

class Data_Damage_State_Format_2 : public Data_Damage_State {
public:
	Data_Damage_State_Format_2(const Packet&);
	virtual ~Data_Damage_State_Format_2() {}

	Vector_UInt brake_damage() const override;
	Vector_UInt suspension_damage() const override;
	unsigned int aero_damage() const override;
	unsigned int engine_damage() const override;

private:
	Packet packet_;
};

}

#endif

