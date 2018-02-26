#include "requestgamestateingamereplay.h"

#include "packet.h"

namespace pcars {

Request_Game_State_In_Game_Replay::Request_Game_State_In_Game_Replay(Request * request)
	: request_{request} {}

bool Request_Game_State_In_Game_Replay::request(std::shared_ptr<Data> data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_INGAME_REPLAY) {
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
