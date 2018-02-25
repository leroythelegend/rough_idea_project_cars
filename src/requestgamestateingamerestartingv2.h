#ifndef PCARS_REQUEST_GAME_STATE_INGAME_RESTART_V2_H_
#define PCARS_REQUEST_GAME_STATE_INGAME_RESTART_V2_H_

#include "request.h"

namespace pcars {

class Request_Game_State_In_Game_Restart_V2 : public Request {
public:
	Request_Game_State_In_Game_Restart_V2(Request *);
	virtual ~Request_Game_State_In_Game_Restart_V2() {}

	bool request(Data *) override;

private:
	Request * request_;
};

}

#endif

