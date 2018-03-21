#include "requestracestateinvalid.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Race_State_Invalid::Request_Race_State_Invalid(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Race_State_Invalid::request(std::shared_ptr<Data> data) {

	if (static_cast<Race_State>(data->game_states()->race_state_flags()) == Race_State::RACESTATE_INVALID) {
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

