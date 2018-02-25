#include "requestgamestateexit.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Game_State_Exit::Request_Game_State_Exit(Request * request)
	: request_{request} {}

bool Request_Game_State_Exit::request(Data * data) {

	if (static_cast<Game_State>(data->game_states()->game_state()) == Game_State::GAME_EXITED) {
		return false;
	}
	else if (request_) {
		return request_->request(data);
	}
	else {
		return true;
	}
}

}
