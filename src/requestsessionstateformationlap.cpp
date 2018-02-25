#include "requestsessionstateformationlap.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Formation_Lap::Request_Session_State_Formation_Lap(Request * request)
	: request_{request} {}

bool Request_Session_State_Formation_Lap::request(Data * data) {

	if (static_cast<Session_State>(data->game_states()->session_state()) == Session_State::SESSION_FORMATION_LAP) {
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

