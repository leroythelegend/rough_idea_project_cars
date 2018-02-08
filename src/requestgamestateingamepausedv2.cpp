#include "requestgamestateingamepausedv2.h"

#include "packet.h"

namespace pcars {

Request_Game_State_In_Game_Paused_V2::Request_Game_State_In_Game_Paused_V2(Request * request)
	: request_{request} {}

bool Request_Game_State_In_Game_Paused_V2::request(Decoder * decoder) {

	Packet * packet = dynamic_cast<Packet *>(decoder);

	if (packet) {

		if (static_cast<Game_State_V2>(packet->game_state().game_state()) == Game_State_V2::GAME_INGAME_PAUSED) {
			return true;
		}

		if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}