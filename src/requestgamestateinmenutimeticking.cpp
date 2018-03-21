#include "requestgamestateinmenutimeticking.h"

namespace pcars {

Request_Game_State_In_Game_Menu_Time_Ticking::Request_Game_State_In_Game_Menu_Time_Ticking(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Game_State_In_Game_Menu_Time_Ticking::request(std::shared_ptr<Data> data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_INGAME_INMENU_TIME_TICKING) {
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
