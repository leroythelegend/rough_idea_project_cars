#include "requestgamestateexit.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Game_State_Exit::Request_Game_State_Exit(Request * request)
	: request_{request} {}

bool Request_Game_State_Exit::request(Decoder * decoder) {

	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->game_state() == Game_State::GAME_EXITED) {
			return false;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}
