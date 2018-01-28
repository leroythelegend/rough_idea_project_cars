#include "requestpitmodeinpit.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_In_Pit::Request_Pit_Mode_In_Pit(Request * request)
	: request_{request} {}

bool Request_Pit_Mode_In_Pit::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->pit_mode() == Pit_Mode::PIT_MODE_IN_PIT) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

