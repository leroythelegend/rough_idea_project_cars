#include "requestgamestateingamepaused.h"

namespace pcars {

Request_Game_State_In_Game_Paused::Request_Game_State_In_Game_Paused(Record_Lap * record, Request * request)
	: record_{record}, 
	  request_{request} {}

bool Request_Game_State_In_Game_Paused::request(std::shared_ptr<Data> data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_INGAME_PAUSED) {
		if (record_) {
			record_->record(data);
		}
		else if (request_) {
			return request_->request(data);
		}
		else {
			return true;
		}
	}
	return true;

}

}

