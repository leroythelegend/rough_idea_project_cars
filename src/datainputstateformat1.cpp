#include "datainputstateformat1.h"

namespace pcars {

Data_Input_State_Format_1::Data_Input_State_Format_1(Decoder_Telemetry_Data * telemetry_data) 
	: telemetry_data_{telemetry_data} {}

float Data_Input_State_Format_1::unfiltered_throttle() const {
	return telemetry_data_->unfiltered_throttle();
}

float Data_Input_State_Format_1::unfiltered_brake() const {
	return telemetry_data_->unfiltered_brake();
}

float Data_Input_State_Format_1::unfiltered_steering() const {
	return telemetry_data_->unfiltered_steering();

}

float Data_Input_State_Format_1::unfiltered_clutch() const {
	return telemetry_data_->unfiltered_clutch();
}


}
	
