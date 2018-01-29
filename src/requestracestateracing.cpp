#include "requestracestateracing.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Race_State_Racing::Request_Race_State_Racing(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Race_State_Racing::request(Decoder * decoder) {
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		if (tdecoder->race_state_flags() == Race_State::RACESTATE_RACING) {
			record_->record(tdecoder);
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

