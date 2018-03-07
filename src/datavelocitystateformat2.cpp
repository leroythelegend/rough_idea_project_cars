#include "datavelocitystateformat2.h"

namespace pcars {

Data_Velocity_State_Format_2::Data_Velocity_State_Format_2(const Packet& packet)
	: packet_{packet} {}

Vector_Float Data_Velocity_State_Format_2::orientation() const {
	return packet_.telemetry_data().orientation();
}

Vector_Float Data_Velocity_State_Format_2::local_velocity() const {
	return packet_.telemetry_data().local_velocity();
}

Vector_Float Data_Velocity_State_Format_2::world_velocity() const {
	return packet_.telemetry_data().world_velocity();
}

Vector_Float Data_Velocity_State_Format_2::angular_velocity() const {
	return packet_.telemetry_data().angular_velocity();
}

Vector_Float Data_Velocity_State_Format_2::local_acceleration() const {
	return packet_.telemetry_data().local_acceleration();
}

Vector_Float Data_Velocity_State_Format_2::world_acceleration() const {
	return packet_.telemetry_data().world_acceleration();
}

Vector_Float Data_Velocity_State_Format_2::extents_centre() const {
	return packet_.telemetry_data().extents_centre();
}

}

