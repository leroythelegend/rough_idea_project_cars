#include "requestpitmodedrivingintopits.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_Driving_Into_Pits::Request_Pit_Mode_Driving_Into_Pits(Request * request)
	: request_{request} {}

bool Request_Pit_Mode_Driving_Into_Pits::request(Data * data) {

	if (static_cast<Pit_Mode>(data->game_states()->pit_mode()) == Pit_Mode::PIT_MODE_DRIVING_INTO_PITS) {
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

