#include "process.h"

#include <utility>
#include <iterator>
#include <fstream>

using namespace std;

namespace pcars {

Process_Lap::Process_Lap()
{
	ofstream reset_file("lap_data.json", ios::trunc);
}

void Process_Lap::process(const Lap_Data & lap_data) const
{
	static unsigned int lap_number;

	std::ofstream file("lap_data.json", ios::app);
	file << "lap" << ++lap_number << " = \'{\"data\":[";

	for (auto iter = lap_data.begin(); iter != lap_data.end(); iter++) {
		file << "{ " << "\"track_distance\":" << "\"" << iter->track_length() << "\","
		      	     << "\"current_distance\":" << "\"" << iter->participant_info().at(0).current_lap_distance() << "\","
		      	     << "\"sector\":" << "\"" << iter->participant_info().at(0).sector() << "\","
		      	     << "\"current_time\":" << "\"" << iter->current_time() << "\","
			     << "\"world_pos_x\":" << "\"" << iter->participant_info().at(0).world_position().at(0) << "\","
			     << "\"world_pos_z\":" << "\"" << iter->participant_info().at(0).world_position().at(2) << "\","
		      	     << "\"brake\":" << "\"" << iter->brake() << "\","
			     << "\"throttle\":" << "\"" << iter->throttle() << "\","
			     << "\"engine_speed\":" << "\"" << iter->engine_speed() << "\","
			     << "\"engine_torque\":" << "\"" << iter->engine_torque() << "\","
			     << "\"fuel_level\":" << "\"" << iter->fuel_level() << "\","
			     << "\"gear\":" << "\"" << iter->gear() << "\","
			     << "\"max_rpm\":" << "\"" << iter->max_rpm() << "\","
			     << "\"rpm\":" << "\"" << iter->rpm() << "\","
			     << "\"speed\":" << "\"" << iter->speed() << "\","
			     << "\"tyre_wear_fl\":" << "\"" << iter->tyre_wear().at(0) << "\","
			     << "\"tyre_wear_fr\":" << "\"" << iter->tyre_wear().at(1) << "\","
			     << "\"tyre_wear_rl\":" << "\"" << iter->tyre_wear().at(2) << "\","
			     << "\"tyre_wear_rr\":" << "\"" << iter->tyre_wear().at(3) << "\","
			     << "\"tyre_slip_speed_fl\":" << "\"" << iter->tyre_slip_speed().at(0) << "\","
			     << "\"tyre_slip_speed_fr\":" << "\"" << iter->tyre_slip_speed().at(1) << "\","
			     << "\"tyre_slip_speed_rl\":" << "\"" << iter->tyre_slip_speed().at(2) << "\","
			     << "\"tyre_slip_speed_rr\":" << "\"" << iter->tyre_slip_speed().at(3) << "\","
			     << "\"tyre_rps_fl\":" << "\"" << iter->tyre_rps().at(0) << "\","
			     << "\"tyre_rps_fr\":" << "\"" << iter->tyre_rps().at(1) << "\","
			     << "\"tyre_rps_rl\":" << "\"" << iter->tyre_rps().at(2) << "\","
			     << "\"tyre_rps_rr\":" << "\"" << iter->tyre_rps().at(3) << "\","
			     << "\"tyre_temp_fl\":" << "\"" << iter->tyre_temp().at(0) << "\","
			     << "\"tyre_temp_fr\":" << "\"" << iter->tyre_temp().at(1) << "\","
			     << "\"tyre_temp_rl\":" << "\"" << iter->tyre_temp().at(2) << "\","
			     << "\"tyre_temp_rr\":" << "\"" << iter->tyre_temp().at(3) << "\","
			     << "\"tyre_tread_temp_fl\":" << "\"" << iter->tyre_tread_temp().at(0) << "\","
			     << "\"tyre_tread_temp_fr\":" << "\"" << iter->tyre_tread_temp().at(1) << "\","
			     << "\"tyre_tread_temp_rl\":" << "\"" << iter->tyre_tread_temp().at(2) << "\","
			     << "\"tyre_tread_temp_rr\":" << "\"" << iter->tyre_tread_temp().at(3) << "\","
			     << "\"tyre_rim_temp_fl\":" << "\"" << iter->tyre_rim_temp().at(0) << "\","
			     << "\"tyre_rim_temp_fr\":" << "\"" << iter->tyre_rim_temp().at(1) << "\","
			     << "\"tyre_rim_temp_rl\":" << "\"" << iter->tyre_rim_temp().at(2) << "\","
			     << "\"tyre_rim_temp_rr\":" << "\"" << iter->tyre_rim_temp().at(3) << "\","
			     << "\"tyre_layer_temp_fl\":" << "\"" << iter->tyre_layer_temp().at(0) << "\","
			     << "\"tyre_layer_temp_fr\":" << "\"" << iter->tyre_layer_temp().at(1) << "\","
			     << "\"tyre_layer_temp_rl\":" << "\"" << iter->tyre_layer_temp().at(2) << "\","
			     << "\"tyre_layer_temp_rr\":" << "\"" << iter->tyre_layer_temp().at(3) << "\","
			     << "\"tyre_height_above_ground_fl\":" << "\"" << iter->tyre_height_above_ground().at(0) << "\","
			     << "\"tyre_height_above_ground_fr\":" << "\"" << iter->tyre_height_above_ground().at(1) << "\","
			     << "\"tyre_height_above_ground_rl\":" << "\"" << iter->tyre_height_above_ground().at(2) << "\","
			     << "\"tyre_height_above_ground_rr\":" << "\"" << iter->tyre_height_above_ground().at(3) << "\","
			     << "\"tyre_grip_fl\":" << "\"" << iter->tyre_grip().at(0) << "\","
			     << "\"tyre_grip_fr\":" << "\"" << iter->tyre_grip().at(1) << "\","
			     << "\"tyre_grip_rl\":" << "\"" << iter->tyre_grip().at(2) << "\","
			     << "\"tyre_grip_rr\":" << "\"" << iter->tyre_grip().at(3) << "\","
			     << "\"tyre_carcass_temp_fl\":" << "\"" << iter->tyre_carcass_temp().at(0) << "\","
			     << "\"tyre_carcass_temp_fr\":" << "\"" << iter->tyre_carcass_temp().at(1) << "\","
			     << "\"tyre_carcass_temp_rl\":" << "\"" << iter->tyre_carcass_temp().at(2) << "\","
			     << "\"tyre_carcass_temp_rr\":" << "\"" << iter->tyre_carcass_temp().at(3) << "\","
			     << "\"suspension_velocity_fl\":" << "\"" << iter->suspension_velocity().at(0) << "\","
			     << "\"suspension_velocity_fr\":" << "\"" << iter->suspension_velocity().at(1) << "\","
			     << "\"suspension_velocity_rl\":" << "\"" << iter->suspension_velocity().at(2) << "\","
			     << "\"suspension_velocity_rr\":" << "\"" << iter->suspension_velocity().at(3) << "\","
			     << "\"suspension_travel_fl\":" << "\"" << iter->suspension_travel().at(0) << "\","
			     << "\"suspension_travel_fr\":" << "\"" << iter->suspension_travel().at(1) << "\","
			     << "\"suspension_travel_rl\":" << "\"" << iter->suspension_travel().at(2) << "\","
			     << "\"suspension_travel_rr\":" << "\"" << iter->suspension_travel().at(3) << "\","
			     << "\"ride_height_fl\":" << "\"" << iter->ride_height().at(0) << "\","
			     << "\"ride_height_fr\":" << "\"" << iter->ride_height().at(1) << "\","
			     << "\"ride_height_rl\":" << "\"" << iter->ride_height().at(2) << "\","
			     << "\"ride_height_rr\":" << "\"" << iter->ride_height().at(3) << "\","
			     << "\"brake_temp_fl\":" << "\"" << iter->brake_temp_celsius().at(0) << "\","
			     << "\"brake_temp_fr\":" << "\"" << iter->brake_temp_celsius().at(1) << "\","
			     << "\"brake_temp_rl\":" << "\"" << iter->brake_temp_celsius().at(2) << "\","
			     << "\"brake_temp_rr\":" << "\"" << iter->brake_temp_celsius().at(3) << "\"";
		if (std::next(iter) != lap_data.end()) {
		        file << "},";	    
		}
		else {
			file <<	"}";
		}
	}

	file << "]}\';" << endl;
}

Process_Track::Process_Track()
{
	ofstream reset_file("track.json", ios::trunc);
}

void Process_Track::process(const Lap_Data & lap_data) const
{
	static unsigned int lap_number;

	std::ofstream file("track.json", ios::app);
	file << "lap" << ++lap_number << " = \'{\"data\":[";

	for (auto iter = lap_data.begin(); iter != lap_data.end(); iter++) {
		file << "{ " << "\"d\":" << "\"" << iter->participant_info().at(0).current_lap_distance() << "\","
		      	     << "\"sector\":" << "\"" << iter->participant_info().at(0).sector() << "\","
			     << "\"x\":" << "\"" << iter->participant_info().at(0).world_position().at(0) << "\","
			     << "\"z\":" << "\"" << iter->participant_info().at(0).world_position().at(2) << "\"";
		if (std::next(iter) != lap_data.end()) {
		        file << "},";	    
		}
		else {
			file <<	"}";
		}
	}

	file << "]}\';" << endl;
}


}



