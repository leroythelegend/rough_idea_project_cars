#include "requestsessionstatepractice.h"


namespace pcars {

Request_Session_State_Practice::Request_Session_State_Practice(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Session_State_Practice::request(std::shared_ptr<Data> data) {

	if (static_cast<Session_State>(data->game_states()->session_state()) == Session_State::SESSION_PRACTICE) {
		if (record_) {
			record_->record(data);
		}
		else if (request_) {
			return request_->request(data);
		}
		else {
			return true;
		}
	}
	return true;
}

}

