#include "requestracestatenotstartedv2.h"

#include "packet.h"

namespace pcars {

Request_Race_State_Not_Started_V2::Request_Race_State_Not_Started_V2(Record_Lap * record, Request * request)
	: record_{record},
	  request_{request} {}

bool Request_Race_State_Not_Started_V2::request(Decoder * decoder) {
	Packet * packet = dynamic_cast<Packet *>(decoder);

	if (packet) {
		if (static_cast<Race_State>(packet->timing_data().partcipants().at(0).race_state()) == Race_State::RACESTATE_NOT_STARTED) {
			record_->record(packet);
			return true;
		}
		else if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

