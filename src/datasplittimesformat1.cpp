#include "datasplittimesformat1.h"

namespace pcars {

Data_Split_Times_Format_1::Data_Split_Times_Format_1(Decoder_Telemetry_Data * telemetry_data)
	: telemetry_data_{telemetry_data} {}

unsigned int Data_Split_Times_Format_1::participants_changed_timestamp() const {
	return 0;
}

float Data_Split_Times_Format_1::event_time_remaining() const {
	return telemetry_data_->event_time_remaining();
}

float Data_Split_Times_Format_1::split_time_ahead() const {
	return telemetry_data_->split_time_ahead();
}

float Data_Split_Times_Format_1::split_time_behind() const {
	return telemetry_data_->split_time_behind();
}

float Data_Split_Times_Format_1::split_time() const {
	return telemetry_data_->split_time();
}





}

