#include "requestsessionstatetest.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Test::Request_Session_State_Test(Request * request)
	: request_{request} {}

bool Request_Session_State_Test::request(std::shared_ptr<Data> data) {

	if (static_cast<Session_State>(data->game_states()->session_state()) == Session_State::SESSION_TEST) {
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

