#ifndef PCARS_REQUEST_GAME_STATE_IN_GAME_PAUSED_H_
#define PCARS_REQUEST_GAME_STATE_IN_GAME_PAUSED_H_

#include "request.h"

namespace pcars {

class Request_Game_State_In_Game_Paused : public Request {
public:
	Request_Game_State_In_Game_Paused(Request * request = nullptr);
	virtual ~Request_Game_State_In_Game_Paused() {}

	virtual bool request(Data *);

private:
	Request * request_;
};

}

#endif

