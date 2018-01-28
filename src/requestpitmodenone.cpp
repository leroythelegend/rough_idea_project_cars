#include "requestpitmodenone.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_None::Request_Pit_Mode_None(Request * request)
	: request_{request} {}

bool Request_Pit_Mode_None::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->pit_mode() == Pit_Mode::PIT_MODE_NONE) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

