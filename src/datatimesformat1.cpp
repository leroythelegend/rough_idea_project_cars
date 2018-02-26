#include "datatimesformat1.h"

namespace pcars {

Data_Times_Format_1::Data_Times_Format_1(std::shared_ptr<Decoder_Telemetry_Data> telemetry_data)
	: telemetry_data_{telemetry_data} {}

float Data_Times_Format_1::current_time() const {
	return telemetry_data_->current_time();
}

float Data_Times_Format_1::current_sector1_time() const {
	return telemetry_data_->current_sector1_time();
}

float Data_Times_Format_1::current_sector2_time() const {
	return telemetry_data_->current_sector2_time();
}

float Data_Times_Format_1::current_sector3_time() const {
	return telemetry_data_->current_sector3_time();
}

float Data_Times_Format_1::fastest_sector1_time() const {
	return telemetry_data_->fastest_sector1_time();
}

float Data_Times_Format_1::fastest_sector2_time() const {
	return telemetry_data_->fastest_sector2_time();
}

float Data_Times_Format_1::fastest_sector3_time() const {
	return telemetry_data_->fastest_sector3_time();
}

}

