#include "requestgamestatefrontend.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Game_State_Front_End::Request_Game_State_Front_End(Request * request)
	: request_{request} {
}

bool Request_Game_State_Front_End::request(Decoder * decoder) {

	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->game_state() == Game_State::GAME_FRONT_END) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

