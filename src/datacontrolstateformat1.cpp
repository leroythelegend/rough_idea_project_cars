#include "datacontrolstateformat1.h"

namespace pcars {


Data_Control_State_Format_1::Data_Control_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data> telemetry_data)
	: telemetry_data_{telemetry_data} {}

unsigned int Data_Control_State_Format_1::joy_pad_0() const {
	return telemetry_data_->joy_pad();
}

unsigned int Data_Control_State_Format_1::d_pad() const {
	return telemetry_data_->dpad();
}



}

