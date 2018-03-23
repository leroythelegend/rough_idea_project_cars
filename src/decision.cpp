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

void Absolute_On_Road::evaluate(const Data_Shared_Ptr & data)
{
	if (static_cast<Terrain>(data->car_states()->terrain().at(0)) == Terrain::TERRAIN_ROAD && 
	    static_cast<Terrain>(data->car_states()->terrain().at(1)) == Terrain::TERRAIN_ROAD && 
	    static_cast<Terrain>(data->car_states()->terrain().at(2)) == Terrain::TERRAIN_ROAD && 
	    static_cast<Terrain>(data->car_states()->terrain().at(3)) == Terrain::TERRAIN_ROAD) {
		for(auto& it : true_) {
			it->evaluate(data);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data);
		}
	}
}

void Absolute_Top_Gear::evaluate(const Data_Shared_Ptr & data)
{
	if (data->car_states()->gears() == data->car_states()->gear()) {
		for(auto& it : true_) {
			it->evaluate(data);
		}
	}
	else {
		for(auto& it : false_) {
			it->evaluate(data);
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

void Decision_MAX_RPM::evaluate(const Data_Shared_Ptr & data)
{
	if (data->car_states()->rpm() == data->car_states()->max_rpm()) {
		result_ = true;
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
	conclusion_->conclude(to_string(fl_temp_));
	conclusion_->conclude(to_string(fr_temp_));
	conclusion_->conclude(to_string(rl_temp_));
	conclusion_->conclude(to_string(rr_temp_));

	fl_temp_ = 0;
	fr_temp_ = 0;
	rl_temp_ = 0;
	rr_temp_ = 0;
}

void Decision_MAX_Tyre_Temp::evaluate(const Data_Shared_Ptr & data)
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


}

