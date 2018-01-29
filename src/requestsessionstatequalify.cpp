#include "requestsessionstatequalify.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Qualify::Request_Session_State_Qualify(Record_Lap * record, Request * request)
	: request_{request},
	  racing_{record} {}

bool Request_Session_State_Qualify::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->session_state() == Session_State::SESSION_QUALIFY) {
			return racing_.request(decoder);
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

