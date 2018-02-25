#include "requestracestateracingv2.h"

#include "packet.h"

namespace pcars {

Request_Race_State_Racing_V2::Request_Race_State_Racing_V2(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Race_State_Racing_V2::request(Data * data) {

	if (static_cast<Race_State>(data->game_states()->race_state_flags()) == Race_State::RACESTATE_RACING) {
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

