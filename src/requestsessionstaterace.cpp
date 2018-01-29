#include "requestsessionstaterace.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Race::Request_Session_State_Race(Record_Lap * record, Request * request)
	: request_{request},
	  racing_{record} {}

bool Request_Session_State_Race::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->session_state() == Session_State::SESSION_RACE) {
			return racing_.request(decoder);
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

