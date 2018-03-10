#include "process.h"

#include <utility>
#include <iterator>
#include <fstream>
#include <iostream>

using namespace std;

namespace pcars {

Process_Lap::Process_Lap()
{
	ofstream reset_file("lap_data.json", ios::trunc);
}

void Process_Lap::process(const Lap_Data lap_data) const
{
	static unsigned int lap_number;

	std::ofstream file("lap_data.json", ios::app);
	file << "lap" << ++lap_number << " = \'{\"data\":[";

	std::cout << "Recording Started " << lap_number << std::endl;

	for (auto iter = lap_data.begin(); iter != lap_data.end(); iter++) {
		file << "{ " << "\"track_distance\":" << "\"" << (*iter)->track_states()->track_length() << "\","
		      	     << "\"current_distance\":" << "\"" << (*iter)->participants_info()->current_lap_distance(0) << "\","
		      	     << "\"sector\":" << "\"" << (*iter)->participants_info()->sector(0) << "\","
		      	     << "\"current_time\":" << "\"" << (*iter)->times()->current_time() << "\","
			     << "\"world_pos_x\":" << "\"" << (*iter)->participants_info()->world_position(0).at(0) << "\","
			     << "\"world_pos_z\":" << "\"" << (*iter)->participants_info()->world_position(0).at(2) << "\","
		      	     << "\"brake\":" << "\"" << (*iter)->car_states()->brake() << "\","
			     << "\"throttle\":" << "\"" << (*iter)->car_states()->throttle() << "\","
			     << "\"engine_speed\":" << "\"" << (*iter)->car_states()->engine_speed() << "\","
			     << "\"engine_torque\":" << "\"" << (*iter)->car_states()->engine_torque() << "\","
			     << "\"fuel_level\":" << "\"" << (*iter)->car_states()->fuel_level() << "\","
			     << "\"gear\":" << "\"" << (*iter)->car_states()->gear() << "\","
			     << "\"max_rpm\":" << "\"" << (*iter)->car_states()->max_rpm() << "\","
			     << "\"rpm\":" << "\"" << (*iter)->car_states()->rpm() << "\","
			     << "\"speed\":" << "\"" << (*iter)->car_states()->speed() << "\","
			     << "\"tyre_wear_fl\":" << "\"" << (*iter)->car_states()->tyre_wear().at(0) << "\","
			     << "\"tyre_wear_fr\":" << "\"" << (*iter)->car_states()->tyre_wear().at(1) << "\","
			     << "\"tyre_wear_rl\":" << "\"" << (*iter)->car_states()->tyre_wear().at(2) << "\","
			     << "\"tyre_wear_rr\":" << "\"" << (*iter)->car_states()->tyre_wear().at(3) << "\","
			     << "\"tyre_slip_speed_fl\":" << "\"" << (*iter)->car_states()->tyre_slip_speed().at(0) << "\","
			     << "\"tyre_slip_speed_fr\":" << "\"" << (*iter)->car_states()->tyre_slip_speed().at(1) << "\","
			     << "\"tyre_slip_speed_rl\":" << "\"" << (*iter)->car_states()->tyre_slip_speed().at(2) << "\","
			     << "\"tyre_slip_speed_rr\":" << "\"" << (*iter)->car_states()->tyre_slip_speed().at(3) << "\","
			     << "\"tyre_rps_fl\":" << "\"" << (*iter)->car_states()->tyre_rps().at(0) << "\","
			     << "\"tyre_rps_fr\":" << "\"" << (*iter)->car_states()->tyre_rps().at(1) << "\","
			     << "\"tyre_rps_rl\":" << "\"" << (*iter)->car_states()->tyre_rps().at(2) << "\","
			     << "\"tyre_rps_rr\":" << "\"" << (*iter)->car_states()->tyre_rps().at(3) << "\","
			     << "\"tyre_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_temp().at(0) << "\","
			     << "\"tyre_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_temp().at(1) << "\","
			     << "\"tyre_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_temp().at(2) << "\","
			     << "\"tyre_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_temp().at(3) << "\","
			     << "\"tyre_tread_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(0) << "\","
			     << "\"tyre_tread_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(1) << "\","
			     << "\"tyre_tread_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(2) << "\","
			     << "\"tyre_tread_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(3) << "\","
			     << "\"tyre_rim_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(0) << "\","
			     << "\"tyre_rim_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(1) << "\","
			     << "\"tyre_rim_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(2) << "\","
			     << "\"tyre_rim_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(3) << "\","
			     << "\"tyre_layer_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(0) << "\","
			     << "\"tyre_layer_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(1) << "\","
			     << "\"tyre_layer_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(2) << "\","
			     << "\"tyre_layer_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(3) << "\","
			     << "\"tyre_height_above_ground_fl\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(0) << "\","
			     << "\"tyre_height_above_ground_fr\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(1) << "\","
			     << "\"tyre_height_above_ground_rl\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(2) << "\","
			     << "\"tyre_height_above_ground_rr\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(3) << "\","
			     << "\"tyre_grip_fl\":" << "\"" << (*iter)->car_states()->tyre_grip().at(0) << "\","
			     << "\"tyre_grip_fr\":" << "\"" << (*iter)->car_states()->tyre_grip().at(1) << "\","
			     << "\"tyre_grip_rl\":" << "\"" << (*iter)->car_states()->tyre_grip().at(2) << "\","
			     << "\"tyre_grip_rr\":" << "\"" << (*iter)->car_states()->tyre_grip().at(3) << "\","
			     << "\"tyre_carcass_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(0) << "\","
			     << "\"tyre_carcass_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(1) << "\","
			     << "\"tyre_carcass_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(2) << "\","
			     << "\"tyre_carcass_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(3) << "\","
			     << "\"suspension_velocity_fl\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(0) << "\","
			     << "\"suspension_velocity_fr\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(1) << "\","
			     << "\"suspension_velocity_rl\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(2) << "\","
			     << "\"suspension_velocity_rr\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(3) << "\","
			     << "\"suspension_travel_fl\":" << "\"" << (*iter)->car_states()->suspension_travel().at(0) << "\","
			     << "\"suspension_travel_fr\":" << "\"" << (*iter)->car_states()->suspension_travel().at(1) << "\","
			     << "\"suspension_travel_rl\":" << "\"" << (*iter)->car_states()->suspension_travel().at(2) << "\","
			     << "\"suspension_travel_rr\":" << "\"" << (*iter)->car_states()->suspension_travel().at(3) << "\","
			     << "\"ride_height_fl\":" << "\"" << (*iter)->car_states()->ride_height().at(0) << "\","
			     << "\"ride_height_fr\":" << "\"" << (*iter)->car_states()->ride_height().at(1) << "\","
			     << "\"ride_height_rl\":" << "\"" << (*iter)->car_states()->ride_height().at(2) << "\","
			     << "\"ride_height_rr\":" << "\"" << (*iter)->car_states()->ride_height().at(3) << "\","
			     << "\"brake_temp_fl\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(0) << "\","
			     << "\"brake_temp_fr\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(1) << "\","
			     << "\"brake_temp_rl\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(2) << "\","
			     << "\"brake_temp_rr\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(3) << "\"";
		if (std::next(iter) != lap_data.end()) {
		        file << "},";	    
		}
		else {
			file <<	"}";
		}
	}

	file << "]}\';" << endl;
	cout << "Recording Finished " << lap_number << endl;
}

Process_Lap_V2::Process_Lap_V2()
{
	ofstream reset_file("lap_data.json", ios::trunc);
}

void Process_Lap_V2::process(const Lap_Data lap_data) const
{
	static unsigned int lap_number;

	std::ofstream file("lap_data.json", ios::app);
	file << "lap" << ++lap_number << " = \'{\"data\":[";

	for (auto iter = lap_data.begin(); iter != lap_data.end(); iter++) {
		file << "{ " << "\"track_distance\":" << "\"" << (*iter)->track_states()->track_length() << "\","
		      	     << "\"current_distance\":" << "\"" << (*iter)->participants_info()->current_lap_distance(0) << "\","
		      	     << "\"sector\":" << "\"" << (*iter)->participants_info()->sector(0) << "\","
		      	     << "\"current_time\":" << "\"" << (*iter)->times()->current_time() << "\","
			     << "\"world_pos_x\":" << "\"" << (*iter)->participants_info()->world_position(0).at(0) << "\","
			     << "\"world_pos_z\":" << "\"" << (*iter)->participants_info()->world_position(0).at(2) << "\","
		      	     << "\"brake\":" << "\"" << (*iter)->car_states()->brake() << "\","
			     << "\"throttle\":" << "\"" << (*iter)->car_states()->throttle() << "\","
			     << "\"engine_speed\":" << "\"" << (*iter)->car_states()->engine_speed() << "\","
			     << "\"engine_torque\":" << "\"" << (*iter)->car_states()->engine_torque() << "\","
			     << "\"fuel_level\":" << "\"" << (*iter)->car_states()->fuel_level() << "\","
			     << "\"gear\":" << "\"" << (*iter)->car_states()->gear() << "\","
			     << "\"max_rpm\":" << "\"" << (*iter)->car_states()->max_rpm() << "\","
			     << "\"rpm\":" << "\"" << (*iter)->car_states()->rpm() << "\","
			     << "\"speed\":" << "\"" << (*iter)->car_states()->speed() << "\","
			     << "\"tyre_wear_fl\":" << "\"" << (*iter)->car_states()->tyre_wear().at(0) << "\","
			     << "\"tyre_wear_fr\":" << "\"" << (*iter)->car_states()->tyre_wear().at(1) << "\","
			     << "\"tyre_wear_rl\":" << "\"" << (*iter)->car_states()->tyre_wear().at(2) << "\","
			     << "\"tyre_wear_rr\":" << "\"" << (*iter)->car_states()->tyre_wear().at(3) << "\","
			     << "\"tyre_rps_fl\":" << "\"" << (*iter)->car_states()->tyre_rps().at(0) << "\","
			     << "\"tyre_rps_fr\":" << "\"" << (*iter)->car_states()->tyre_rps().at(1) << "\","
			     << "\"tyre_rps_rl\":" << "\"" << (*iter)->car_states()->tyre_rps().at(2) << "\","
			     << "\"tyre_rps_rr\":" << "\"" << (*iter)->car_states()->tyre_rps().at(3) << "\","
			     << "\"tyre_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_temp().at(0) << "\","
			     << "\"tyre_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_temp().at(1) << "\","
			     << "\"tyre_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_temp().at(2) << "\","
			     << "\"tyre_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_temp().at(3) << "\","
			     << "\"tyre_temp_left_fl\":" << "\"" << (*iter)->car_states()->tyre_temp_left().at(0) << "\","
			     << "\"tyre_temp_left_fr\":" << "\"" << (*iter)->car_states()->tyre_temp_left().at(1) << "\","
			     << "\"tyre_temp_left_rl\":" << "\"" << (*iter)->car_states()->tyre_temp_left().at(2) << "\","
			     << "\"tyre_temp_left_rr\":" << "\"" << (*iter)->car_states()->tyre_temp_left().at(3) << "\","
			     << "\"tyre_temp_center_fl\":" << "\"" << (*iter)->car_states()->tyre_temp_center().at(0) << "\","
			     << "\"tyre_temp_center_fr\":" << "\"" << (*iter)->car_states()->tyre_temp_center().at(1) << "\","
			     << "\"tyre_temp_center_rl\":" << "\"" << (*iter)->car_states()->tyre_temp_center().at(2) << "\","
			     << "\"tyre_temp_center_rr\":" << "\"" << (*iter)->car_states()->tyre_temp_center().at(3) << "\","
			     << "\"tyre_temp_right_fl\":" << "\"" << (*iter)->car_states()->tyre_temp_right().at(0) << "\","
			     << "\"tyre_temp_right_fr\":" << "\"" << (*iter)->car_states()->tyre_temp_right().at(1) << "\","
			     << "\"tyre_temp_right_rl\":" << "\"" << (*iter)->car_states()->tyre_temp_right().at(2) << "\","
			     << "\"tyre_temp_right_rr\":" << "\"" << (*iter)->car_states()->tyre_temp_right().at(3) << "\","
			     << "\"tyre_tread_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(0) << "\","
			     << "\"tyre_tread_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(1) << "\","
			     << "\"tyre_tread_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(2) << "\","
			     << "\"tyre_tread_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_tread_temp().at(3) << "\","
			     << "\"tyre_rim_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(0) << "\","
			     << "\"tyre_rim_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(1) << "\","
			     << "\"tyre_rim_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(2) << "\","
			     << "\"tyre_rim_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_rim_temp().at(3) << "\","
			     << "\"tyre_layer_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(0) << "\","
			     << "\"tyre_layer_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(1) << "\","
			     << "\"tyre_layer_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(2) << "\","
			     << "\"tyre_layer_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_layer_temp().at(3) << "\","
			     << "\"tyre_height_above_ground_fl\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(0) << "\","
			     << "\"tyre_height_above_ground_fr\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(1) << "\","
			     << "\"tyre_height_above_ground_rl\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(2) << "\","
			     << "\"tyre_height_above_ground_rr\":" << "\"" << (*iter)->car_states()->tyre_height_above_ground().at(3) << "\","
			     << "\"tyre_carcass_temp_fl\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(0) << "\","
			     << "\"tyre_carcass_temp_fr\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(1) << "\","
			     << "\"tyre_carcass_temp_rl\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(2) << "\","
			     << "\"tyre_carcass_temp_rr\":" << "\"" << (*iter)->car_states()->tyre_carcass_temp().at(3) << "\","
			     << "\"suspension_velocity_fl\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(0) << "\","
			     << "\"suspension_velocity_fr\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(1) << "\","
			     << "\"suspension_velocity_rl\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(2) << "\","
			     << "\"suspension_velocity_rr\":" << "\"" << (*iter)->car_states()->suspension_velocity().at(3) << "\","
			     << "\"suspension_travel_fl\":" << "\"" << (*iter)->car_states()->suspension_travel().at(0) << "\","
			     << "\"suspension_travel_fr\":" << "\"" << (*iter)->car_states()->suspension_travel().at(1) << "\","
			     << "\"suspension_travel_rl\":" << "\"" << (*iter)->car_states()->suspension_travel().at(2) << "\","
			     << "\"suspension_travel_rr\":" << "\"" << (*iter)->car_states()->suspension_travel().at(3) << "\","
			     << "\"ride_height_fl\":" << "\"" << (*iter)->car_states()->ride_height().at(0) << "\","
			     << "\"ride_height_fr\":" << "\"" << (*iter)->car_states()->ride_height().at(1) << "\","
			     << "\"ride_height_rl\":" << "\"" << (*iter)->car_states()->ride_height().at(2) << "\","
			     << "\"ride_height_rr\":" << "\"" << (*iter)->car_states()->ride_height().at(3) << "\","
			     << "\"brake_temp_fl\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(0) << "\","
			     << "\"brake_temp_fr\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(1) << "\","
			     << "\"brake_temp_rl\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(2) << "\","
			     << "\"brake_temp_rr\":" << "\"" << (*iter)->car_states()->brake_temp_celsius().at(3) << "\","
			     << "\"track_name\":" << "\"" << (*iter)->track_states()->track_location() << "_" << (*iter)->track_states()->track_variation() << "\"";
		if (std::next(iter) != lap_data.end()) {
		        file << "},";	    
		}
		else {
			file <<	"}";
		}
	}

	file << "]}\';" << endl;
	cout << "Recording Finished " << lap_number << endl;
}



Process_Track::Process_Track()
{
	ofstream reset_file("track.json", ios::trunc);
}

void Process_Track::process(const Lap_Data lap_data) const
{
	static unsigned int lap_number;

	std::ofstream file("track.json", ios::app);
	file << "lap" << ++lap_number << " = \'{\"data\":[";

	for (auto iter = lap_data.begin(); iter != lap_data.end(); iter++) {
		file << "{ " << "\"d\":" << "\"" <<(*iter)->participants_info()->current_lap_distance(0) << "\","
		      	     << "\"sector\":" << "\"" << (*iter)->participants_info()->sector(0) << "\","
			     << "\"x\":" << "\"" << (*iter)->participants_info()->world_position(0).at(0) << "\","
			     << "\"z\":" << "\"" << (*iter)->participants_info()->world_position(0).at(2) << "\"";
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



