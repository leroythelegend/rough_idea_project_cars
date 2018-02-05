#include "requestgamestateinmenutimetickingv2.h"

#include "packet.h"

namespace pcars {

Request_Game_State_In_Game_Menu_Time_Ticking_V2::Request_Game_State_In_Game_Menu_Time_Ticking_V2(Request * request)
	: request_{request} {}

bool Request_Game_State_In_Game_Menu_Time_Ticking_V2::request(Decoder * decoder) {

	Packet * packet = dynamic_cast<Packet *>(decoder);

	if (packet) {

		if (static_cast<Game_State_V2>(packet->game_state().game_state()) == Game_State_V2::GAME_INGAME_INMENU_TIME_TICKING) {
			return true;
		}

		if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}
