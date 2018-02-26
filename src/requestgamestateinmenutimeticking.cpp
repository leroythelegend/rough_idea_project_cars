#include "requestgamestateinmenutimeticking.h"

#include "packet.h"

namespace pcars {

Request_Game_State_In_Game_Menu_Time_Ticking::Request_Game_State_In_Game_Menu_Time_Ticking(Request * request)
	: request_{request} {}

bool Request_Game_State_In_Game_Menu_Time_Ticking::request(std::shared_ptr<Data> data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_INGAME_INMENU_TIME_TICKING) {
		return true;
	} 
	else if (request_) {
		return request_->request(data);
	}
	else {
		return true;
	}
}

}
