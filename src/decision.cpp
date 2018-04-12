#include "decision.h"

#include <iostream>

using namespace std;

namespace pcars {

void Absolute::if_true(Decision_Shared_Ptr decision)
{
	true_.push_back(decision);
}

void Absolute::if_false(Decision_Shared_Ptr decision)
{
	false_.push_back(decision);
}

void Absolute_On_Road::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (static_cast<Terrain>(data->car_states()->terrain().at(0)) == Terrain::TERRAIN_ROAD && 
	    static_cast<Terrain>(data->car_states()->terrain().at(1)) == Terrain::TERRAIN_ROAD && 
	    static_cast<Terrain>(data->car_states()->terrain().at(2)) == Terrain::TERRAIN_ROAD && 
	    static_cast<Terrain>(data->car_states()->terrain().at(3)) == Terrain::TERRAIN_ROAD) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}

void Absolute_On_Road_FL::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (static_cast<Terrain>(data->car_states()->terrain().at(0)) == Terrain::TERRAIN_ROAD) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}

void Absolute_On_Road_FR::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (static_cast<Terrain>(data->car_states()->terrain().at(1)) == Terrain::TERRAIN_ROAD) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}


void Absolute_On_Road_RL::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (static_cast<Terrain>(data->car_states()->terrain().at(2)) == Terrain::TERRAIN_ROAD) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}


void Absolute_On_Road_RR::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (static_cast<Terrain>(data->car_states()->terrain().at(3)) == Terrain::TERRAIN_ROAD) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}


Absolute_Brake_GT::Absolute_Brake_GT(const Brake brake)
	: brake_{brake} {}

void Absolute_Brake_GT::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (data->car_states()->brake() > brake_) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}


void Absolute_2_Tyres_On_Road::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if ((static_cast<Terrain>(data->car_states()->terrain().at(0)) == Terrain::TERRAIN_ROAD && 
	     static_cast<Terrain>(data->car_states()->terrain().at(2)) == Terrain::TERRAIN_ROAD) || 
	    (static_cast<Terrain>(data->car_states()->terrain().at(1)) == Terrain::TERRAIN_ROAD && 
	     static_cast<Terrain>(data->car_states()->terrain().at(3)) == Terrain::TERRAIN_ROAD)) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}
Absolute_Gear::Absolute_Gear(const Gear gear) 
	: gear_{gear} {}

void Absolute_Gear::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (gear_ <= data->car_states()->gears()) {
		if (gear_ == data->car_states()->gear()) {
			for(auto& it : true_) {
				it->evaluate(data, lap_data_size, pos);
			}
		}
		else {
			for(auto& it : false_) {
				it->evaluate(data, lap_data_size, pos);
			}
		}
	}
}


void Absolute_Top_Gear::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (data->car_states()->gears() == data->car_states()->gear()) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}

void Absolute_Steering_Straight::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (data->car_states()->steering() == 0) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}

void Absolute_Full_Throttle::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (data->car_states()->throttle() > 250) {
		for(auto& it : true_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data, lap_data_size, pos);
		}
	}
}


Conclusion_Cout::Conclusion_Cout(const Outcome & outcome)
	: outcome1_{outcome}
{
}

Conclusion_Cout::Conclusion_Cout(const Outcome & outcome1,
				 const Outcome & outcome2,
				 const Outcome & outcome3,
				 const Outcome & outcome4)
	: outcome1_{outcome1},
	  outcome2_{outcome2},
	  outcome3_{outcome3},
	  outcome4_{outcome4}
{
}

void Conclusion_Cout::conclude(const Result_OutCome & result) const
{
	cout << outcome1_ << result << endl;
}

void Conclusion_Cout::conclude(const Result_OutCome & result1,
			       const Result_OutCome & result2,
			       const Result_OutCome & result3,
			       const Result_OutCome & result4) const
{
	cout << outcome1_ << result1 << endl;
	cout << outcome2_ << result2 << endl;
	cout << outcome3_ << result3 << endl;
	cout << outcome4_ << result4 << endl;
}

Decision_MAX_RPM::Decision_MAX_RPM(Conclusion_Ptr conclusion)
	: result_{false},
	  conclusion_{conclusion}
{
}

void Decision_MAX_RPM::result()
{
	if (result_) {
		conclusion_->conclude("TRUE");
	}

	result_ = false;
}

void Decision_MAX_RPM::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->rpm() == data->car_states()->max_rpm()) {
		result_ = true;
	}
}

Decision_RPM_GT_Percent::Decision_RPM_GT_Percent(Conclusion_Ptr conclusion, const Percent percent)
	: result_{false},
	  conclusion_{conclusion},
	  percent_{percent}
{
}

void Decision_RPM_GT_Percent::result()
{
	if (result_) {
		conclusion_->conclude("TRUE");
	}
	else {
		conclusion_->conclude("FALSE");
	}

	result_ = false;
}

void Decision_RPM_GT_Percent::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->rpm() > (data->car_states()->max_rpm() * static_cast<double>((static_cast<double>(percent_)/100)))) {
		result_ = true;
	}
}

Decision_Percent_Per_Lap::Decision_Percent_Per_Lap(Conclusion_Ptr conclusion)
	: count_{0},
	  percent_{0},
	  conclusion_{conclusion}
{
}

void Decision_Percent_Per_Lap::result()
{
	conclusion_->conclude(to_string(percent_));

	count_ = 0;
	percent_ = 0;
}

void Decision_Percent_Per_Lap::evaluate(const Data_Shared_Ptr & , const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	++count_;
	if (lap_data_size == pos) {
		percent_ = (count_/static_cast<double>(lap_data_size)) * 100;
	}
}

Decision_MAX_Tyre_Temp::Decision_MAX_Tyre_Temp(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  fl_temp_{0},
	  fr_temp_{0},
	  rl_temp_{0},
	  rr_temp_{0}
{
}

void Decision_MAX_Tyre_Temp::result()
{
	conclusion_->conclude(to_string(fl_temp_),
	                      to_string(fr_temp_),
	                      to_string(rl_temp_),
	                      to_string(rr_temp_));

	fl_temp_ = 0;
	fr_temp_ = 0;
	rl_temp_ = 0;
	rr_temp_ = 0;
}

void Decision_MAX_Tyre_Temp::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->tyre_temp().at(0) > fl_temp_) {
		fl_temp_ = data->car_states()->tyre_temp().at(0);
	}
	if (data->car_states()->tyre_temp().at(1) > fr_temp_) {
		fr_temp_ = data->car_states()->tyre_temp().at(1);
	}
	if (data->car_states()->tyre_temp().at(2) > rl_temp_) {
		rl_temp_ = data->car_states()->tyre_temp().at(2);
	}
	if (data->car_states()->tyre_temp().at(3) > rr_temp_) {
		rr_temp_ = data->car_states()->tyre_temp().at(3);
	}
}

Decision_MAX_Tyre_Slip_Speed::Decision_MAX_Tyre_Slip_Speed(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  fl_slip_speed_{0},
	  fr_slip_speed_{0},
	  rl_slip_speed_{0},
	  rr_slip_speed_{0}
{
}

void Decision_MAX_Tyre_Slip_Speed::result()
{
	conclusion_->conclude(to_string(fl_slip_speed_),
	                      to_string(fr_slip_speed_),
	                      to_string(rl_slip_speed_),
	                      to_string(rr_slip_speed_));

	fl_slip_speed_ = 0;
	fr_slip_speed_ = 0;
	rl_slip_speed_ = 0;
	rr_slip_speed_ = 0;
}

void Decision_MAX_Tyre_Slip_Speed::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->tyre_slip_speed().at(0) > fl_slip_speed_) {
		fl_slip_speed_ = data->car_states()->tyre_slip_speed().at(0);
	}
	if (data->car_states()->tyre_slip_speed().at(1) > fr_slip_speed_) {
		fr_slip_speed_ = data->car_states()->tyre_slip_speed().at(1);
	}
	if (data->car_states()->tyre_slip_speed().at(2) > rl_slip_speed_) {
		rl_slip_speed_ = data->car_states()->tyre_slip_speed().at(2);
	}
	if (data->car_states()->tyre_slip_speed().at(3) > rr_slip_speed_) {
		rr_slip_speed_ = data->car_states()->tyre_slip_speed().at(3);
	}
}


Decision_MAX_Brake_Temp::Decision_MAX_Brake_Temp(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  fl_temp_{0},
	  fr_temp_{0},
	  rl_temp_{0},
	  rr_temp_{0}
{
}

void Decision_MAX_Brake_Temp::result()
{
	conclusion_->conclude(to_string(fl_temp_),
	                      to_string(fr_temp_),
	                      to_string(rl_temp_),
	                      to_string(rr_temp_));

	fl_temp_ = 0;
	fr_temp_ = 0;
	rl_temp_ = 0;
	rr_temp_ = 0;
}

void Decision_MAX_Brake_Temp::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->brake_temp_celsius().at(0) > fl_temp_) {
		fl_temp_ = data->car_states()->brake_temp_celsius().at(0);
	}
	if (data->car_states()->brake_temp_celsius().at(1) > fr_temp_) {
		fr_temp_ = data->car_states()->brake_temp_celsius().at(1);
	}
	if (data->car_states()->brake_temp_celsius().at(2) > rl_temp_) {
		rl_temp_ = data->car_states()->brake_temp_celsius().at(2);
	}
	if (data->car_states()->brake_temp_celsius().at(3) > rr_temp_) {
		rr_temp_ = data->car_states()->brake_temp_celsius().at(3);
	}
}

Decision_MAX_Tyre_Layer_Temp::Decision_MAX_Tyre_Layer_Temp(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  fl_temp_{0},
	  fr_temp_{0},
	  rl_temp_{0},
	  rr_temp_{0}
{
}

void Decision_MAX_Tyre_Layer_Temp::result()
{
	conclusion_->conclude(to_string(fl_temp_),
	                      to_string(fr_temp_),
	                      to_string(rl_temp_),
	                      to_string(rr_temp_));

	fl_temp_ = 0;
	fr_temp_ = 0;
	rl_temp_ = 0;
	rr_temp_ = 0;
}

void Decision_MAX_Tyre_Layer_Temp::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->tyre_layer_temp().at(0) > fl_temp_) {
		fl_temp_ = data->car_states()->tyre_layer_temp().at(0);
	}
	if (data->car_states()->tyre_layer_temp().at(1) > fr_temp_) {
		fr_temp_ = data->car_states()->tyre_layer_temp().at(1);
	}
	if (data->car_states()->tyre_layer_temp().at(2) > rl_temp_) {
		rl_temp_ = data->car_states()->tyre_layer_temp().at(2);
	}
	if (data->car_states()->tyre_layer_temp().at(3) > rr_temp_) {
		rr_temp_ = data->car_states()->tyre_layer_temp().at(3);
	}
}




Decision_MAX_Speed::Decision_MAX_Speed(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  speed_{0}
{
}

void Decision_MAX_Speed::result()
{
	conclusion_->conclude(to_string(speed_));

	speed_ = 0;
}

void Decision_MAX_Speed::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->speed() > speed_) {
		speed_ = data->car_states()->speed();
	}
}

Decision_MIN_FL_Ride_Height::Decision_MIN_FL_Ride_Height(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  height_{1000}
{
}

void Decision_MIN_FL_Ride_Height::result()
{
	conclusion_->conclude(to_string(height_));

	height_ = 1000;
}

void Decision_MIN_FL_Ride_Height::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->ride_height().at(0) < height_) {
		height_ = data->car_states()->ride_height().at(0);
	}
}

Decision_MIN_FR_Ride_Height::Decision_MIN_FR_Ride_Height(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  height_{1000}
{
}

void Decision_MIN_FR_Ride_Height::result()
{
	conclusion_->conclude(to_string(height_));

	height_ = 1000;
}

void Decision_MIN_FR_Ride_Height::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->ride_height().at(1) < height_) {
		height_ = data->car_states()->ride_height().at(1);
	}
}

Decision_MIN_RL_Ride_Height::Decision_MIN_RL_Ride_Height(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  height_{1000}
{
}

void Decision_MIN_RL_Ride_Height::result()
{
	conclusion_->conclude(to_string(height_));

	height_ = 1000;
}

void Decision_MIN_RL_Ride_Height::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->ride_height().at(2) < height_) {
		height_ = data->car_states()->ride_height().at(2);
	}
}

Decision_MIN_RR_Ride_Height::Decision_MIN_RR_Ride_Height(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  height_{1000}
{
}

void Decision_MIN_RR_Ride_Height::result()
{
	conclusion_->conclude(to_string(height_));

	height_ = 1000;
}

void Decision_MIN_RR_Ride_Height::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size, const Lap_Pos)
{
	if (data->car_states()->ride_height().at(3) < height_) {
		height_ = data->car_states()->ride_height().at(3);
	}
}

Decision_Lap_Time::Decision_Lap_Time(Conclusion_Ptr conclusion)
	: conclusion_{conclusion},
	  lap_time_{0}
{
}

void Decision_Lap_Time::result()
{
	conclusion_->conclude(to_string(lap_time_));

	lap_time_ = 0;
}

void Decision_Lap_Time::evaluate(const Data_Shared_Ptr & data, const Lap_Data_Size lap_data_size, const Lap_Pos pos)
{
	if (pos == lap_data_size) {
		lap_time_ = data->times()->current_time();
	}
}



}

