#include "requestracestatenotstartedv2.h"

#include "packet.h"

namespace pcars {

Request_Race_State_Not_Started_V2::Request_Race_State_Not_Started_V2(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Race_State_Not_Started_V2::request(Data * data) {

	if (static_cast<Race_State>(data->game_states()->race_state_flags()) == Race_State::RACESTATE_NOT_STARTED) {
		record_->record(data);
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

