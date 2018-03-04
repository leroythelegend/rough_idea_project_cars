#include "datadamagestateformat2.h"

namespace pcars {

Data_Damage_State_Format_2::Data_Damage_State_Format_2(std::shared_ptr<Packet> packet)
	: packet_{packet} {}
	
Vector_UInt Data_Damage_State_Format_2::brake_damage() const {
	return packet_->telemetry_data().brake_damage();
}

Vector_UInt Data_Damage_State_Format_2::suspension_damage() const {
	return packet_->telemetry_data().suspension_damage();
}

unsigned int Data_Damage_State_Format_2::aero_damage() const {
	return packet_->telemetry_data().aero_damage();
}

unsigned int Data_Damage_State_Format_2::engine_damage() const {
	return packet_->telemetry_data().engine_damage();
}




}

