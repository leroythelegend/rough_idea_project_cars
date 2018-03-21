#include "requestracestatenotstarted.h"

namespace pcars {

Request_Race_State_Not_Started::Request_Race_State_Not_Started(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Race_State_Not_Started::request(std::shared_ptr<Data> data) {

	if (static_cast<Race_State>(data->game_states()->race_state_flags()) == Race_State::RACESTATE_NOT_STARTED) {
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

