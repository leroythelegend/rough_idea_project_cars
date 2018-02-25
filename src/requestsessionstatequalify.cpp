#include "requestsessionstatequalify.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Qualify::Request_Session_State_Qualify(Record_Lap * record, Request * request)
	: request_{request},
	  racing_{record} {}

bool Request_Session_State_Qualify::request(Data * data) {

	if (static_cast<Session_State>(data->game_states()->session_state()) == Session_State::SESSION_QUALIFY) {
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

