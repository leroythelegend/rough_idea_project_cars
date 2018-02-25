#include "requestpitmodeinpit.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_In_Pit::Request_Pit_Mode_In_Pit(Request * request)
	: request_{request} {}

bool Request_Pit_Mode_In_Pit::request(Data * data) {

	if (static_cast<Pit_Mode>(data->game_states()->pit_mode()) == Pit_Mode::PIT_MODE_IN_PIT) {
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

