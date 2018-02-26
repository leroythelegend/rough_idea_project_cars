#include "requestgamestatefrontendreplay.h"

#include "packet.h"

namespace pcars {

Request_Game_State_Front_End_Replay::Request_Game_State_Front_End_Replay(Request * request)
	: request_{request} {}

bool Request_Game_State_Front_End_Replay::request(std::shared_ptr<Data> data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_FRONT_END_REPLAY) {
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
