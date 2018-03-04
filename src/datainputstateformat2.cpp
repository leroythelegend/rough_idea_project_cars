#include "datainputstateformat2.h"

namespace pcars {

Data_Input_State_Format_2::Data_Input_State_Format_2(std::shared_ptr<Packet> packet) 
	: packet_{packet} {}

float Data_Input_State_Format_2::unfiltered_throttle() const {
	return packet_->telemetry_data().unfiltered_throttle();
}

float Data_Input_State_Format_2::unfiltered_brake() const {
	return packet_->telemetry_data().unfiltered_brake();
}

float Data_Input_State_Format_2::unfiltered_steering() const {
	return packet_->telemetry_data().unfiltered_steering();

}

float Data_Input_State_Format_2::unfiltered_clutch() const {
	return packet_->telemetry_data().unfiltered_clutch();
}


}
	
