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
	: outcome_{outcome}
{
}

void Conclusion_Cout::conclude(const Result_OutCome & result) const
{
	cout << outcome_ << result << endl;
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
	else {
		conclusion_->conclude("FASLE");
	}
}

void Decision_MAX_RPM::evaluate(const Data_Shared_Ptr & data)
{
	if (data->car_states()->rpm() == data->car_states()->max_rpm()) {
		result_ = true;
	}
}


}

