#include "requestpitmodenone.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_None::Request_Pit_Mode_None(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Pit_Mode_None::request(std::shared_ptr<Data> data) {

	if (static_cast<Pit_Mode>(data->game_states()->pit_mode()) == Pit_Mode::PIT_MODE_NONE) {
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

