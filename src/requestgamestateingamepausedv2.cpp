#include "requestgamestateingamepausedv2.h"

#include "packet.h"

namespace pcars {

Request_Game_State_In_Game_Paused_V2::Request_Game_State_In_Game_Paused_V2(Request * request)
	: request_{request} {}

bool Request_Game_State_In_Game_Paused_V2::request(Data * data) {

	if (static_cast<Game_State_V2>(data->game_states()->game_state()) == Game_State_V2::GAME_INGAME_PAUSED) {
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
