#include "dataformat1.h"

#include "decodergeneric.h"
#include "datacarstateformat1.h"
#include "datagamestateformat1.h"
#include "datainputstateformat1.h"
#include "datavelocitystateformat1.h"
#include "datadamagestateformat1.h"
#include "datacontrolstateformat1.h"
#include "datatrackstateformat1.h"
#include "dataparticipantsformat1.h"
#include "dataparticipantsinfoformat1.h"
#include "dataparticipantsstatsformat1.h"
#include "datasplittimesformat1.h"
#include "datatimesformat1.h"

namespace pcars {

Data_Format_1::Data_Format_1(std::shared_ptr<Decoder_Telemetry_Data> decoder)
	: car_state_{std::make_unique<Data_Car_State_Format_1>(decoder)},
	  game_state_{std::make_unique<Data_Game_State_Format_1>(decoder)},
	  input_state_{std::make_unique<Data_Input_State_Format_1>(decoder)},
	  velocity_state_{std::make_unique<Data_Velocity_State_Format_1>(decoder)},
	  damage_state_{std::make_unique<Data_Damage_State_Format_1>(decoder)},
	  control_state_{std::make_unique<Data_Control_State_Format_1>(decoder)},
	  track_state_{std::make_unique<Data_Track_State_Format_1>(decoder)},
	  participants_{std::make_unique<Data_Participants_Format_1>()}, 
	  participants_info_{std::make_unique<Data_Participants_Info_Format_1>(decoder)},
	  participants_stats_{std::make_unique<Data_Participants_Stats_Format_1>()},
	  split_times_{std::make_unique<Data_Split_Times_Format_1>(decoder)},
	  times_{std::make_unique<Data_Times_Format_1>(decoder)} {}

Data_Car_State * Data_Format_1::car_states() const {
	return car_state_.get();
}

Data_Game_State * Data_Format_1::game_states() const {
	return game_state_.get();
}

Data_Input_State * Data_Format_1::input_states() const {
	return input_state_.get();
}

Data_Velocity_State * Data_Format_1::velocity_states() const {
	return velocity_state_.get();
}

Data_Damage_State * Data_Format_1::damage_states() const {
	return damage_state_.get();
}

Data_Control_State * Data_Format_1::control_states() const {
	return control_state_.get();
}

Data_Track_State * Data_Format_1::track_states() const {
	return track_state_.get();
}

Data_Participants * Data_Format_1::participants() const {
	return participants_.get();
}

Data_Participants_Info * Data_Format_1::participants_info() const {
	return participants_info_.get();
}

Data_Participants_Stats * Data_Format_1::participants_stats() const {
	return participants_stats_.get();
}

Data_Split_Times * Data_Format_1::split_times() const {
	return split_times_.get();
}

Data_Times * Data_Format_1::times() const {
	return times_.get();
}

}

