#include "requestsessionstatepracticev2.h"

#include "packet.h"

namespace pcars {

Request_Session_State_Practice_V2::Request_Session_State_Practice_V2(Record_Lap * record, Request * request)
	: request_{request},
	  racing_{record} {}

bool Request_Session_State_Practice_V2::request(Decoder * decoder) {

	Packet * packet = dynamic_cast<Packet *>(decoder);

	if (packet) {

		if (static_cast<Session_State>(packet->game_state().sessin_state()) == Session_State::SESSION_PRACTICE) {
			return racing_.request(decoder);
		}

		if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

