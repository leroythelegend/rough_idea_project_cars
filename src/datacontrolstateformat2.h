#ifndef PCARS_DATA_CONTROL_STATE_FORMAT_2_H_
#define PCARS_DATA_CONTROL_STATE_FORMAT_2_H_

#include "datacontrolstate.h"
#include "packet.h"

namespace pcars {

class Data_Control_State_Format_2 : public Data_Control_State {
public:
	Data_Control_State_Format_2(std::shared_ptr<Packet>);
	virtual ~Data_Control_State_Format_2() {}

	unsigned int joy_pad_0() const override;
	unsigned int d_pad() const override;

private:
	std::shared_ptr<Packet> packet_;
};

}

#endif

