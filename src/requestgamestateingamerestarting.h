#ifndef PCARS_REQUEST_GAME_STATE_INGAME_RESTART_H_
#define PCARS_REQUEST_GAME_STATE_INGAME_RESTART_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Game_State_In_Game_Restart : public Request {
public:
	Request_Game_State_In_Game_Restart(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Game_State_In_Game_Restart() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;
};

}

#endif

