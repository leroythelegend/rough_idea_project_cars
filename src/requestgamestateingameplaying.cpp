#include "requestgamestateingameplaying.h"

namespace pcars {

Request_Game_State_In_Game_Playing::Request_Game_State_In_Game_Playing(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Game_State_In_Game_Playing::request(std::shared_ptr<Data> data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_INGAME_PLAYING) {
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


