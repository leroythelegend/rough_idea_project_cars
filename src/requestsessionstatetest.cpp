#include "requestsessionstatetest.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Test::Request_Session_State_Test(Request * request)
	: request_{request} {}

bool Request_Session_State_Test::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->session_state() == Session_State::SESSION_TEST) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}


}

