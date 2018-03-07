#include "datagamestateformat1.h"

namespace pcars {

Data_Game_State_Format_1::Data_Game_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data> telemetry_data)
	: telemetry_data_{telemetry_data} {}

unsigned int Data_Game_State_Format_1::session_state() const {
	return telemetry_data_->session_state();
}

unsigned int Data_Game_State_Format_1::game_state() const {
	return telemetry_data_->game_state();
}

unsigned int Data_Game_State_Format_1::race_state_flags() const {
	return telemetry_data_->race_state_flags();
}

unsigned int Data_Game_State_Format_1::pit_mode() const {
	return telemetry_data_->pit_mode();
}

}
	
