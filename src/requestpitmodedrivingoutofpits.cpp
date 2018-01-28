#include "requestpitmodedrivingoutofpits.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_Driving_Out_Of_Pits::Request_Pit_Mode_Driving_Out_Of_Pits(Request * request)
	: request_{request} {}

bool Request_Pit_Mode_Driving_Out_Of_Pits::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->pit_mode() == Pit_Mode::PIT_MODE_DRIVING_OUT_OF_PITS) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

