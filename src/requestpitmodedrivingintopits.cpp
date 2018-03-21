#include "requestpitmodedrivingintopits.h"

namespace pcars {

Request_Pit_Mode_Driving_Into_Pits::Request_Pit_Mode_Driving_Into_Pits(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Pit_Mode_Driving_Into_Pits::request(std::shared_ptr<Data> data) {

	if (static_cast<Pit_Mode>(data->game_states()->pit_mode()) == Pit_Mode::PIT_MODE_DRIVING_INTO_PITS) {
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

