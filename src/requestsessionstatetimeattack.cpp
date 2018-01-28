#include "requestsessionstatetimeattack.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Time_Attack::Request_Session_State_Time_Attack(Request * request)
	: request_{request} {
}

bool Request_Session_State_Time_Attack::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->session_state() == Session_State::SESSION_TIME_ATTACK) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

