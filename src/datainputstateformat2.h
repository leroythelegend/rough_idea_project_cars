#ifndef PCARS_DATA_INPUT_STATE_FORMAT_2_H_
#define PCARS_DATA_INPUT_STATE_FORMAT_2_H_

#include "datainputstate.h"
#include "packet.h"

namespace pcars {

class Data_Input_State_Format_2 : public Data_Input_State {
public:
	Data_Input_State_Format_2(std::shared_ptr<Packet>);
	virtual ~Data_Input_State_Format_2() {}

	float unfiltered_throttle() const override;
	float unfiltered_brake() const override;
	float unfiltered_steering() const override;
	float unfiltered_clutch() const override;

private:
	std::shared_ptr<Packet> packet_;
};

}

#endif

