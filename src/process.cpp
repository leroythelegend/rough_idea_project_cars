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

Process_Decision_Tree::Process_Decision_Tree()
{
	// Decision > tyres2_on_road
	// Decision > On_Road
	// Decision > Tyre_Temp
	std::shared_ptr<Decision> tyres2_on_road = std::make_shared<Absolute_2_Tyres_On_Road>();  
	std::shared_ptr<Decision> on_road = std::make_shared<Absolute_On_Road>();  
	std::shared_ptr<Decision_MAX_Tyre_Temp> tyre_temp =  std::make_shared<Decision_MAX_Tyre_Temp>(std::make_shared<Conclusion_Cout>("FL MAX Tyre Temp ",
	  "FR MAX Tyre Temp ",
	  "RL MAX Tyre Temp ",
	  "RR MAX Tyre Temp "));
	decisions_.push_back(tyres2_on_road);
	decisions_.push_back(on_road);
	decisions_.push_back(tyre_temp);
	// Decision > tyres2_on_road T full_throttle
	std::shared_ptr<Decision> full_throttle = std::make_shared<Absolute_Full_Throttle>();  
	tyres2_on_road->if_true(full_throttle);
	// Decision > tyres2_on_road T gear_1st 
	std::shared_ptr<Decision> gear_1st = std::make_shared<Absolute_Gear>(1);  
	tyres2_on_road->if_true(gear_1st);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_1st
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_1st
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_1st = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("1st gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_1st = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("1st gear rpm greater than 95% "), 95);
	gear_1st->if_true(rpm_gt_90_1st);
	gear_1st->if_true(rpm_gt_95_1st);
	// Decision > tyres2_on_road T gear_2st 
	std::shared_ptr<Decision> gear_2nd = std::make_shared<Absolute_Gear>(2);  
	tyres2_on_road->if_true(gear_2nd);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_2nd
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_2nd
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_2nd = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("2nd gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_2nd = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("2nd gear rpm greater than 95% "), 95);
	gear_2nd->if_true(rpm_gt_90_2nd);
	gear_2nd->if_true(rpm_gt_95_2nd);
	// Decision > tyres2_on_road T gear_3rd 
	std::shared_ptr<Decision> gear_3rd = std::make_shared<Absolute_Gear>(3);  
	tyres2_on_road->if_true(gear_3rd);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_3rd
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_3rd
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_3rd = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("3rd gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_3rd = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("3rd gear rpm greater than 95% "), 95);
	gear_3rd->if_true(rpm_gt_90_3rd);
	gear_3rd->if_true(rpm_gt_95_3rd);
	// Decision > tyres2_on_road T gear_4th 
	std::shared_ptr<Decision> gear_4th = std::make_shared<Absolute_Gear>(4);  
	tyres2_on_road->if_true(gear_4th);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_4th
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_4th
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_4th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("4th gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_4th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("4th gear rpm greater than 95% "), 95);
	gear_4th->if_true(rpm_gt_90_4th);
	gear_4th->if_true(rpm_gt_95_4th);
	// Decision > tyres2_on_road T gear_5th 
	std::shared_ptr<Decision> gear_5th = std::make_shared<Absolute_Gear>(5);  
	tyres2_on_road->if_true(gear_5th);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_5th
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_5th
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_5th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("5th gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_5th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("5th gear rpm greater than 95% "), 95);
	gear_5th->if_true(rpm_gt_90_5th);
	gear_5th->if_true(rpm_gt_95_5th);
	// Decision > tyres2_on_road T gear_6th 
	std::shared_ptr<Decision> gear_6th = std::make_shared<Absolute_Gear>(6);  
	tyres2_on_road->if_true(gear_6th);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_6th
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_6th
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_6th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("6th gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_6th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("6th gear rpm greater than 95% "), 95);
	gear_6th->if_true(rpm_gt_90_6th);
	gear_6th->if_true(rpm_gt_95_6th);
	// Decision > tyres2_on_road T gear_7th 
	std::shared_ptr<Decision> gear_7th = std::make_shared<Absolute_Gear>(7);  
	tyres2_on_road->if_true(gear_7th);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_7th
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_7th
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_7th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("7th gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_7th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("7th gear rpm greater than 95% "), 95);
	gear_7th->if_true(rpm_gt_90_7th);
	gear_7th->if_true(rpm_gt_95_7th);
	// Decision > tyres2_on_road T gear_8th 
	std::shared_ptr<Decision> gear_8th = std::make_shared<Absolute_Gear>(8);  
	tyres2_on_road->if_true(gear_8th);
	// Decision > tyres2_on_road T gear_1st T rpm_gt_90_8th
	// Decision > tyres2_on_road T gear_1st T rpm_gt_95_8th
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90_8th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("8th gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95_8th = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("8th gear rpm greater than 95% "), 95);
	gear_8th->if_true(rpm_gt_90_8th);
	gear_8th->if_true(rpm_gt_95_8th);
	// Decision > On_Road T Top_Gear
	std::shared_ptr<Decision> top_gear = std::make_shared<Absolute_Top_Gear>();  
	on_road->if_true(top_gear);
	// Decision > tyres2_on_road T full_throttle T percent_full_throttle
	std::shared_ptr<Decision_Percent_Per_Lap> percent_full_throttle = std::make_shared<Decision_Percent_Per_Lap>(std::make_shared<Conclusion_Cout>("Percent full throttle per lap "));
	full_throttle->if_true(percent_full_throttle);
	// Decision > On_Road T Top_Gear T MAX_RPM
	// Decision > On_Road T Top_Gear T RPM_GT_90
	// Decision > On_Road T Top_Gear T RPM_GT_95
	std::shared_ptr<Decision_MAX_RPM> max_rpm = std::make_shared<Decision_MAX_RPM>(std::make_shared<Conclusion_Cout>("Top gear hit max rpms "));
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90 = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("Top gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95 = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("Top gear rpm greater than 95% "), 95);
	top_gear->if_true(max_rpm);
	top_gear->if_true(rpm_gt_90);
	top_gear->if_true(rpm_gt_95);

	// Results
	results_.push_back(percent_full_throttle);
	results_.push_back(max_rpm);
	results_.push_back(rpm_gt_90);
	results_.push_back(rpm_gt_95);
	results_.push_back(rpm_gt_90_1st);
	results_.push_back(rpm_gt_95_1st);
	results_.push_back(rpm_gt_90_2nd);
	results_.push_back(rpm_gt_95_2nd);
	results_.push_back(rpm_gt_90_3rd);
	results_.push_back(rpm_gt_95_3rd);
	results_.push_back(rpm_gt_90_4th);
	results_.push_back(rpm_gt_95_4th);
	results_.push_back(rpm_gt_90_5th);
	results_.push_back(rpm_gt_95_5th);
	results_.push_back(rpm_gt_90_6th);
	results_.push_back(rpm_gt_95_6th);
	results_.push_back(rpm_gt_90_7th);
	results_.push_back(rpm_gt_95_7th);
	results_.push_back(rpm_gt_90_8th);
	results_.push_back(rpm_gt_95_8th);
	results_.push_back(tyre_temp);

}

void Process_Decision_Tree::capture_session(const Lap_Data& lap_data) {
	laps_data_.push_back(lap_data);
}

void Process_Decision_Tree::process_session()
{
	if (laps_data_.size()) {
		cout << "Started Processing" << endl;
		unsigned int lap_number = 0;
		for (auto& lap_it : laps_data_) {
			++lap_number;
			cout << "Evaluate Lap " << lap_number << endl;
			for (auto& d_it : decisions_) {
				unsigned int pos = 0;
				for (auto& it : lap_it) {
					d_it->evaluate(it, lap_it.size(), ++pos);
				}
			}
			for (auto& it : results_) {
				it->result();
			}
		}
		laps_data_.clear();
		cout << "Finished Processing" << endl;
	}
}

}



