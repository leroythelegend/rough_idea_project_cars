#include "requestsessionstaterace.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Race::Request_Session_State_Race(Record_Lap * record, Request * request)
	: request_{request},
	  racing_{record} {}

bool Request_Session_State_Race::request(std::shared_ptr<Data> data) {

	if (static_cast<Session_State>(data->game_states()->session_state()) == Session_State::SESSION_RACE) {
		return racing_.request(data);
	}
	else if (request_) {
		return request_->request(data);
	}
	else {
		return true;
	}
}

}

