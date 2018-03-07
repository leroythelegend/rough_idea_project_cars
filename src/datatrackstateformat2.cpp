#include "datatrackstateformat2.h"

namespace pcars {

Data_Track_State_Format_2::Data_Track_State_Format_2(const Packet& packet)
	: packet_{packet} {}

float Data_Track_State_Format_2::world_fastest_lap_time() const {
	return packet_.race_data().world_fastest_lap_time();
}

float Data_Track_State_Format_2::personal_fastest_lap_time() const {
	return packet_.race_data().personal_fastest_lap_time();
}

float Data_Track_State_Format_2::personal_fastest_sector1_time() const  {
	return packet_.race_data().personal_fastest_sector1_time();
}

float Data_Track_State_Format_2::personal_fastest_sector2_time() const  {
	return packet_.race_data().personal_fastest_sector2_time();
}

float Data_Track_State_Format_2::personal_fastest_sector3_time() const  {
	return packet_.race_data().personal_fastest_sector3_time();
}

float Data_Track_State_Format_2::world_fastest_sector1_time() const  {
	return packet_.race_data().world_fastest_sector1_time();
}

float Data_Track_State_Format_2::world_fastest_sector2_time() const  {
	return packet_.race_data().world_fastest_sector2_time();
}

float Data_Track_State_Format_2::world_fastest_sector3_time() const  {
	return packet_.race_data().world_fastest_sector3_time();
}

float Data_Track_State_Format_2::track_length() const  {
	return packet_.race_data().track_length();
}

std::string Data_Track_State_Format_2::track_location() const  {
	return packet_.race_data().track_location();
}

std::string Data_Track_State_Format_2::track_variation() const  {
	return packet_.race_data().track_variation();
}	

std::string Data_Track_State_Format_2::translated_track_location() const  {
	return packet_.race_data().translated_track_location();
}

std::string Data_Track_State_Format_2::translated_track_variation() const  {
	return packet_.race_data().translated_track_variation();
}

unsigned int Data_Track_State_Format_2::laps_time_in_event() const  {
	return packet_.race_data().laps_time_in_event();
}

int Data_Track_State_Format_2::enforced_pitstop_lap() const  {
	return packet_.race_data().enforced_pitstop_lap();
}

int Data_Track_State_Format_2::ambient_temp() const {
	return packet_.game_state().ambient_temperature();
}

int Data_Track_State_Format_2::track_temp() const {
	return packet_.game_state().track_temperature();
}

unsigned int Data_Track_State_Format_2::rain_density() const {
	return packet_.game_state().rain_density();
}

unsigned int Data_Track_State_Format_2::snow_density() const {
	return packet_.game_state().snow_density();
}

int Data_Track_State_Format_2::wind_speed() const {
	return packet_.game_state().wind_speed();
}

int Data_Track_State_Format_2::wind_direction_x() const {
	return packet_.game_state().wind_direction_x();
}

int Data_Track_State_Format_2::wind_direction_y() const {
	return packet_.game_state().wind_direction_y();
}

}

