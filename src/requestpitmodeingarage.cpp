#include "requestpitmodeingarage.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_In_Garage::Request_Pit_Mode_In_Garage(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Pit_Mode_In_Garage::request(std::shared_ptr<Data> data) {

	if (static_cast<Pit_Mode>(data->game_states()->pit_mode()) == Pit_Mode::PIT_MODE_IN_GARAGE) {
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

