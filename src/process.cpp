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
	// Decision > On_Road_FL
	// Decision > On_Road_FR
	// Decision > On_Road_RL
	// Decision > On_Road_RR
	// Decision > Brake 
	// Decision > Tyre_Temp
	// Decision > Brake_Temp
	// Decision > Lap_Time 
	// Decision > Speed 
	std::shared_ptr<Decision> tyres2_on_road = std::make_shared<Absolute_2_Tyres_On_Road>();  
	std::shared_ptr<Decision> on_road = std::make_shared<Absolute_On_Road>();  
	std::shared_ptr<Decision> on_road_fl = std::make_shared<Absolute_On_Road_FL>();  
	std::shared_ptr<Decision> on_road_fr = std::make_shared<Absolute_On_Road_FR>();  
	std::shared_ptr<Decision> on_road_rl = std::make_shared<Absolute_On_Road_RL>();  
	std::shared_ptr<Decision> on_road_rr = std::make_shared<Absolute_On_Road_RR>();  
	std::shared_ptr<Decision> brake = std::make_shared<Absolute_Brake_GT>(50);  
	std::shared_ptr<Decision> braking_right = std::make_shared<Absolute_Brake_GT>(10);  
	std::shared_ptr<Decision> throttle_right = std::make_shared<Absolute_Throttle_GT>(10);  
	std::shared_ptr<Decision> coast_right = std::make_shared<Absolute_Coast>();  
	std::shared_ptr<Decision_MAX_Tyre_Temp> tyre_temp =  std::make_shared<Decision_MAX_Tyre_Temp>(std::make_shared<Conclusion_Cout>("FL MAX Tyre Temp ",
	  "FR MAX Tyre Temp ",
	  "RL MAX Tyre Temp ",
	  "RR MAX Tyre Temp "));
	std::shared_ptr<Decision_MAX_Brake_Temp> brake_temp =  std::make_shared<Decision_MAX_Brake_Temp>(std::make_shared<Conclusion_Cout>("FL MAX Brake Temp ",
	  "FR MAX Brake Temp ",
	  "RL MAX Brake Temp ",
	  "RR MAX Brake Temp "));
	std::shared_ptr<Decision_Lap_Time> lap_time =  std::make_shared<Decision_Lap_Time>(std::make_shared<Conclusion_Cout>("Time "));
	std::shared_ptr<Decision_MAX_Tyre_Layer_Temp> brake_layer_temp = std::make_shared<Decision_MAX_Tyre_Layer_Temp>(std::make_shared<Conclusion_Cout>("FL MAX Braking Tyre Layer Temp ",
	  "FR MAX Braking Tyre Layer Temp ",
	  "RL MAX Braking Tyre Layer Temp ",
	  "RR MAX Braking Tyre Layer Temp "));  
	std::shared_ptr<Decision_MAX_Tyre_Slip_Speed> brake_slip_speed = std::make_shared<Decision_MAX_Tyre_Slip_Speed>(std::make_shared<Conclusion_Cout>("FL MAX Braking Tyre Slip Speed ",
	  "FR MAX Braking Tyre Slip Speed ",
	  "RL MAX Braking Tyre Slip Speed ",
	  "RR MAX Braking Tyre Slip Speed "));  
std::shared_ptr<Decision_MAX_Speed> speed =  std::make_shared<Decision_MAX_Speed>(std::make_shared<Conclusion_Cout>("Top Speed "));
	std::shared_ptr<Decision> full_throttle = std::make_shared<Absolute_Full_Throttle>();  
	std::shared_ptr<Decision> top_gear = std::make_shared<Absolute_Top_Gear>();  
	std::shared_ptr<Decision_Percent_Per_Lap> percent_full_throttle = std::make_shared<Decision_Percent_Per_Lap>(std::make_shared<Conclusion_Cout>("Percent full throttle per lap "));
	std::shared_ptr<Decision_MAX_RPM> max_rpm = std::make_shared<Decision_MAX_RPM>(std::make_shared<Conclusion_Cout>("Top gear hit max rpms "));
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_90 = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("Top gear rpm greater than 90% "), 90);
	std::shared_ptr<Decision_RPM_GT_Percent> rpm_gt_95 = std::make_shared<Decision_RPM_GT_Percent>(std::make_shared<Conclusion_Cout>("Top gear rpm greater than 95% "), 95);
	std::shared_ptr<Decision_MIN_FL_Ride_Height> ride_height_fl = std::make_shared<Decision_MIN_FL_Ride_Height>(std::make_shared<Conclusion_Cout>("Ride height fl MIN "));
	std::shared_ptr<Decision_MIN_FR_Ride_Height> ride_height_fr = std::make_shared<Decision_MIN_FR_Ride_Height>(std::make_shared<Conclusion_Cout>("Ride height fr MIN "));
	std::shared_ptr<Decision_MIN_RL_Ride_Height> ride_height_rl = std::make_shared<Decision_MIN_RL_Ride_Height>(std::make_shared<Conclusion_Cout>("Ride height rl MIN "));
	std::shared_ptr<Decision_MIN_RR_Ride_Height> ride_height_rr = std::make_shared<Decision_MIN_RR_Ride_Height>(std::make_shared<Conclusion_Cout>("Ride height rr MIN "));
	std::shared_ptr<Decision> turning_right = std::make_shared<Absolute_Turn_Right_Between>(0, 100);
	std::shared_ptr<Decision_MAX_Tyre_Temps_FL> temps_fl_brake = std::make_shared<Decision_MAX_Tyre_Temps_FL>(std::make_shared<Conclusion_Cout>("MAX Temp FL Left turning right and braking ",
	                                      "MAX Temp FL Centre turning right and braking ",
					      "MAX Temp FL Right turning right and braking "));
	std::shared_ptr<Decision_MAX_Tyre_Temps_FL> temps_fl_throttle = std::make_shared<Decision_MAX_Tyre_Temps_FL>(std::make_shared<Conclusion_Cout>("MAX Temp FL Left turning right and throttle ",
	                                      "MAX Temp FL Centre turning right and throttle ",
					      "MAX Temp FL Right turning right and throttle "));
	std::shared_ptr<Decision_MAX_Tyre_Temps_FL> temps_fl_coast = std::make_shared<Decision_MAX_Tyre_Temps_FL>(std::make_shared<Conclusion_Cout>("MAX Temp FL Left turning right and coast ",
	                                      "MAX Temp FL Centre turning right and coast ",
					      "MAX Temp FL Right turning right and coast "));

	decisions_.push_back(tyres2_on_road);
	decisions_.push_back(on_road);
	decisions_.push_back(on_road_fl);
	decisions_.push_back(on_road_fr);
	decisions_.push_back(on_road_rl);
	decisions_.push_back(on_road_rr);
	decisions_.push_back(brake);
	decisions_.push_back(tyre_temp);
	decisions_.push_back(brake_temp);
	decisions_.push_back(lap_time);
	decisions_.push_back(speed);

	brake->if_true(brake_layer_temp);
	brake->if_true(brake_slip_speed);

	tyres2_on_road->if_true(full_throttle);

	on_road->if_true(top_gear);

	full_throttle->if_true(percent_full_throttle);

	top_gear->if_true(max_rpm);
	top_gear->if_true(rpm_gt_90);
	top_gear->if_true(rpm_gt_95);

	on_road_fl->if_true(ride_height_fl);
	on_road_fr->if_true(ride_height_fr);
	on_road_rl->if_true(ride_height_rl);
	on_road_rr->if_true(ride_height_rr);
	on_road_fl->if_true(turning_right);

	turning_right->if_true(braking_right);
	turning_right->if_true(throttle_right);
	turning_right->if_true(coast_right);

	braking_right->if_true(temps_fl_brake);
	throttle_right->if_true(temps_fl_throttle);
	coast_right->if_true(temps_fl_coast);

	// Results
	results_.push_back(lap_time);
	results_.push_back(speed);
	results_.push_back(percent_full_throttle);
	results_.push_back(max_rpm);
	results_.push_back(rpm_gt_90);
	results_.push_back(rpm_gt_95);
	results_.push_back(tyre_temp);
	results_.push_back(brake_temp);
	results_.push_back(brake_layer_temp);
	results_.push_back(brake_slip_speed);
	results_.push_back(ride_height_fl);
	results_.push_back(ride_height_fr);
	results_.push_back(ride_height_rl);
	results_.push_back(ride_height_rr);
	results_.push_back(temps_fl_brake);
	results_.push_back(temps_fl_throttle);
	results_.push_back(temps_fl_coast);

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



