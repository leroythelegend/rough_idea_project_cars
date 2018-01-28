#include "requestgamestateingamepaused.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Game_State_In_Game_Paused::Request_Game_State_In_Game_Paused(Request * request)
	: request_{request} {	
}

bool Request_Game_State_In_Game_Paused::request(Decoder * decoder) {

	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->game_state() == Game_State::GAME_INGAME_PAUSED) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

