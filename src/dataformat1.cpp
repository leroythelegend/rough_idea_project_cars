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

Data_Format_1::Data_Format_1(Decoder * decoder)
	: car_state_{nullptr} {

	Decoder_Generic * gdecoder = dynamic_cast<Decoder_Generic *>(decoder);

	if (gdecoder->packet_type() == Packet_Type::PACKET_TYPE_TELEMETRY) {
		car_state_.reset(new Data_Car_State_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		game_state_.reset(new Data_Game_State_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		input_state_.reset(new Data_Input_State_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		velocity_state_.reset(new Data_Velocity_State_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		damage_state_.reset(new Data_Damage_State_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		control_state_.reset(new Data_Control_State_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		track_state_.reset(new Data_Track_State_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		participants_.reset(new Data_Participants_Format_1);	
		participants_info_.reset(new Data_Participants_Info_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		participants_stats_.reset(new Data_Participants_Stats_Format_1);	
		split_times_.reset(new Data_Split_Times_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
		times_.reset(new Data_Times_Format_1(dynamic_cast<Decoder_Telemetry_Data *>(decoder)));	
	}
	else {
		throw 1;
	}
}

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
