#include "requestpitmodeingarage.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Pit_Mode_In_Garage::Request_Pit_Mode_In_Garage(Request * request)
	: request_{request} {}

bool Request_Pit_Mode_In_Garage::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->pit_mode() == Pit_Mode::PIT_MODE_IN_GARAGE) {
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

