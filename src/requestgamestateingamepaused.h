#ifndef PCARS_REQUEST_GAME_STATE_IN_GAME_PAUSED_H_
#define PCARS_REQUEST_GAME_STATE_IN_GAME_PAUSED_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Game_State_In_Game_Paused : public Request {
public:
	Request_Game_State_In_Game_Paused(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Game_State_In_Game_Paused() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;
};

}

#endif

