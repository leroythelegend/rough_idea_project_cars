#include "datatrackstateformat1.h"

namespace pcars {

Data_Track_State_Format_1::Data_Track_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data> telemetry_data)
	: telemetry_data_{telemetry_data} {}

float Data_Track_State_Format_1::world_fastest_lap_time() const {
	return telemetry_data_->world_fastest_lap_time();
}

float Data_Track_State_Format_1::personal_fastest_lap_time() const {
	return telemetry_data_->personal_fastest_lap_time();
}

float Data_Track_State_Format_1::personal_fastest_sector1_time() const  {
	return telemetry_data_->personal_fastest_sector1_time();
}

float Data_Track_State_Format_1::personal_fastest_sector2_time() const  {
	return telemetry_data_->personal_fastest_sector2_time();
}

float Data_Track_State_Format_1::personal_fastest_sector3_time() const  {
	return telemetry_data_->personal_fastest_sector3_time();
}

float Data_Track_State_Format_1::world_fastest_sector1_time() const  {
	return telemetry_data_->world_fastest_sector1_time();
}

float Data_Track_State_Format_1::world_fastest_sector2_time() const  {
	return telemetry_data_->world_fastest_sector2_time();
}

float Data_Track_State_Format_1::world_fastest_sector3_time() const  {
	return telemetry_data_->world_fastest_sector3_time();
}

float Data_Track_State_Format_1::track_length() const  {
	return telemetry_data_->track_length();
}

std::string Data_Track_State_Format_1::track_location() const  {
	return "";
}

std::string Data_Track_State_Format_1::track_variation() const  {
	return "";
}	

std::string Data_Track_State_Format_1::translated_track_location() const  {
	return "";
}

std::string Data_Track_State_Format_1::translated_track_variation() const  {
	return "";
}

unsigned int Data_Track_State_Format_1::laps_time_in_event() const  {
	return telemetry_data_->laps_in_event();
}

int Data_Track_State_Format_1::enforced_pitstop_lap() const  {
	return telemetry_data_->enforced_pit_stop_lap();
}

int Data_Track_State_Format_1::ambient_temp() const {
	return telemetry_data_->ambient_temperature();
}

int Data_Track_State_Format_1::track_temp() const {
	return telemetry_data_->track_temperature();
}

unsigned int Data_Track_State_Format_1::rain_density() const {
	return telemetry_data_->rain_density();
}

unsigned int Data_Track_State_Format_1::snow_density() const {
	return 0;
}

int Data_Track_State_Format_1::wind_speed() const {
	return telemetry_data_->wind_speed();
}

int Data_Track_State_Format_1::wind_direction_x() const {
	return telemetry_data_->wind_direction_x();
}

int Data_Track_State_Format_1::wind_direction_y() const {
	return telemetry_data_->wind_direction_y();
}

}

