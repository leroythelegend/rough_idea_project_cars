#include "datagamestateformat2.h"

namespace pcars {

Data_Game_State_Format_2::Data_Game_State_Format_2(const Packet& packet)
	: packet_{packet} {}

unsigned int Data_Game_State_Format_2::session_state() const {
	return packet_.game_state().sessin_state();
}

unsigned int Data_Game_State_Format_2::game_state() const {
	return packet_.game_state().game_state();
}

unsigned int Data_Game_State_Format_2::race_state_flags() const {
	return packet_.timing_data().partcipants().at(0).race_state();
}

unsigned int Data_Game_State_Format_2::pit_mode() const {
	return packet_.timing_data().partcipants().at(0).pit_mode();
}

}
	
