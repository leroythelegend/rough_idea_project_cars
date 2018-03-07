#ifndef PCARS_DATA_FORMAT_2_H_
#define PCARS_DATA_FORMAT_2_H_

#include <memory>

#include "data.h"
#include "packet.h"

namespace pcars {

class Data_Format_2 : public Data {
public:
	Data_Format_2(const Packet);
	virtual ~Data_Format_2() {}

	Data_Car_State * car_states() const override;	
	Data_Game_State * game_states() const override;
	Data_Input_State * input_states() const override;
	Data_Velocity_State * velocity_states() const override;
	Data_Damage_State * damage_states() const override;
	Data_Control_State * control_states() const override;
	Data_Track_State * track_states() const override;
	Data_Participants * participants() const override;
	Data_Participants_Info * participants_info() const override;
	Data_Participants_Stats * participants_stats() const override;
	Data_Split_Times * split_times() const override;
	Data_Times * times() const override;

private:
	std::shared_ptr<Data_Car_State> car_state_;
	std::shared_ptr<Data_Game_State> game_state_;
	std::shared_ptr<Data_Input_State> input_state_;
	std::shared_ptr<Data_Velocity_State> velocity_state_;
	std::shared_ptr<Data_Damage_State> damage_state_;
	std::shared_ptr<Data_Control_State> control_state_;
	std::shared_ptr<Data_Track_State> track_state_;
	std::shared_ptr<Data_Participants> participants_;
	std::shared_ptr<Data_Participants_Info> participants_info_;
	std::shared_ptr<Data_Participants_Stats> participants_stats_;
	std::shared_ptr<Data_Split_Times> split_times_;
	std::shared_ptr<Data_Times> times_;
};

}

#endif

