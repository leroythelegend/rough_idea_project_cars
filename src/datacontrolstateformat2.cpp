#include "datacontrolstateformat2.h"

namespace pcars {


Data_Control_State_Format_2::Data_Control_State_Format_2(const Packet& packet)
	: packet_{packet} {}

unsigned int Data_Control_State_Format_2::joy_pad_0() const {
	return packet_.telemetry_data().joy_pad_0();
}

unsigned int Data_Control_State_Format_2::d_pad() const {
	return packet_.telemetry_data().d_pad();
}



}

