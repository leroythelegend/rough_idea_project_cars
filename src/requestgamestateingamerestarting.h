#ifndef PCARS_REQUEST_GAME_STATE_INGAME_RESTART_H_
#define PCARS_REQUEST_GAME_STATE_INGAME_RESTART_H_

#include "request.h"

namespace pcars {

class Request_Game_State_In_Game_Restart : public Request {
public:
	Request_Game_State_In_Game_Restart(Request *);
	virtual ~Request_Game_State_In_Game_Restart() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Request * request_;
};

}

#endif

