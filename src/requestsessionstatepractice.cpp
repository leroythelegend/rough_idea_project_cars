#include "requestsessionstatepractice.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Practice::Request_Session_State_Practice(Record_Lap * record, Request * request)
	: request_{request},
	  racing_{record} {}

bool Request_Session_State_Practice::request(Data * data) {

	if (static_cast<Session_State>(data->game_states()->session_state()) == Session_State::SESSION_PRACTICE) {
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

