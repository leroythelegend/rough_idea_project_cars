#include "datadamagestateformat1.h"

namespace pcars {

Data_Damage_State_Format_1::Data_Damage_State_Format_1(Decoder_Telemetry_Data * telemetry_data)
	: telemetry_data_{telemetry_data} {}
	
Vector_UInt Data_Damage_State_Format_1::brake_damage() const {
	return telemetry_data_->brake_damage();
}

Vector_UInt Data_Damage_State_Format_1::suspension_damage() const {
	return telemetry_data_->suspension_damage();
}

unsigned int Data_Damage_State_Format_1::aero_damage() const {
	return telemetry_data_->aero_damage();
}

unsigned int Data_Damage_State_Format_1::engine_damage() const {
	return telemetry_data_->engine_damage();
}




}

