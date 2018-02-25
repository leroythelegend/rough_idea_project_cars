#include "requestracestateracing.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Race_State_Racing::Request_Race_State_Racing(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Race_State_Racing::request(Data * data) {

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

