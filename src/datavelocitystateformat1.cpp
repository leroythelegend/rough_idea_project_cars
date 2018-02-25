#include "datavelocitystateformat1.h"

namespace pcars {

Data_Velocity_State_Format_1::Data_Velocity_State_Format_1(Decoder_Telemetry_Data * telemetry_data)
	: telemetry_data_{telemetry_data} {}

Vector_Float Data_Velocity_State_Format_1::orientation() const {
	return telemetry_data_->orientation();
}

Vector_Float Data_Velocity_State_Format_1::local_velocity() const {
	return telemetry_data_->local_velocity();
}

Vector_Float Data_Velocity_State_Format_1::world_velocity() const {
	return telemetry_data_->world_velocity();
}

Vector_Float Data_Velocity_State_Format_1::angular_velocity() const {
	return telemetry_data_->angular_velocity();
}

Vector_Float Data_Velocity_State_Format_1::local_acceleration() const {
	return telemetry_data_->local_acceleration();
}

Vector_Float Data_Velocity_State_Format_1::world_acceleration() const {
	return telemetry_data_->world_acceleration();
}

Vector_Float Data_Velocity_State_Format_1::extents_centre() const {
	return telemetry_data_->extents_centre();
}

}

