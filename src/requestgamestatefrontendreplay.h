#ifndef PCARS_REQUEST_GAME_STATE_FRONT_END_REPLAY_H_
#define PCARS_REQUEST_GAME_STATE_FRONT_END_REPLAY_H_

#include "request.h"

namespace pcars {

class Request_Game_State_Front_End_Replay : public Request {
public:
	Request_Game_State_Front_End_Replay(Request *);
	virtual ~Request_Game_State_Front_End_Replay() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Request * request_;
};

}

#endif

