#include "dataformat2.h"

#include "decodergeneric.h"
#include "datacarstateformat2.h"
#include "datagamestateformat2.h"
#include "datainputstateformat2.h"
#include "datavelocitystateformat2.h"
#include "datadamagestateformat2.h"
#include "datacontrolstateformat2.h"
#include "datatrackstateformat2.h"
#include "dataparticipantsformat2.h"
#include "dataparticipantsinfoformat2.h"
#include "dataparticipantsstatsformat2.h"
#include "datasplittimesformat2.h"
#include "datatimesformat2.h"

namespace pcars {

Data_Format_2::Data_Format_2(std::shared_ptr<Packet> packet)
	: car_state_{std::make_unique<Data_Car_State_Format_2>(packet)},
	  game_state_{std::make_unique<Data_Game_State_Format_2>(packet)},
	  input_state_{std::make_unique<Data_Input_State_Format_2>(packet)},
	  velocity_state_{std::make_unique<Data_Velocity_State_Format_2>(packet)},
	  damage_state_{std::make_unique<Data_Damage_State_Format_2>(packet)},
	  control_state_{std::make_unique<Data_Control_State_Format_2>(packet)},
	  track_state_{std::make_unique<Data_Track_State_Format_2>(packet)},
	  participants_{std::make_unique<Data_Participants_Format_2>(packet)}, 
	  participants_info_{std::make_unique<Data_Participants_Info_Format_2>(packet)},
	  participants_stats_{std::make_unique<Data_Participants_Stats_Format_2>(packet)},
	  split_times_{std::make_unique<Data_Split_Times_Format_2>(packet)},
	  times_{std::make_unique<Data_Times_Format_2>(packet)} {}

Data_Car_State * Data_Format_2::car_states() const {
	return car_state_.get();
}

Data_Game_State * Data_Format_2::game_states() const {
	return game_state_.get();
}

Data_Input_State * Data_Format_2::input_states() const {
	return input_state_.get();
}

Data_Velocity_State * Data_Format_2::velocity_states() const {
	return velocity_state_.get();
}

Data_Damage_State * Data_Format_2::damage_states() const {
	return damage_state_.get();
}

Data_Control_State * Data_Format_2::control_states() const {
	return control_state_.get();
}

Data_Track_State * Data_Format_2::track_states() const {
	return track_state_.get();
}

Data_Participants * Data_Format_2::participants() const {
	return participants_.get();
}

Data_Participants_Info * Data_Format_2::participants_info() const {
	return participants_info_.get();
}

Data_Participants_Stats * Data_Format_2::participants_stats() const {
	return participants_stats_.get();
}

Data_Split_Times * Data_Format_2::split_times() const {
	return split_times_.get();
}

Data_Times * Data_Format_2::times() const {
	return times_.get();
}

}

