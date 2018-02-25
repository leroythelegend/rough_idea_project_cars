#include "requestracestatenotstarted.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Race_State_Not_Started::Request_Race_State_Not_Started(Request * request)
	: request_{request} {}

bool Request_Race_State_Not_Started::request(Data * data) {

	if (static_cast<Race_State>(data->game_states()->race_state_flags()) == Race_State::RACESTATE_NOT_STARTED) {
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

