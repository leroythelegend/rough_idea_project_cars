#include "requestgamestatefrontend.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Game_State_Front_End::Request_Game_State_Front_End(Request * request)
	: request_{request} {
}

bool Request_Game_State_Front_End::request(std::shared_ptr<Data> data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_FRONT_END) {
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

