#ifndef PCARS_REQUEST_GAME_STATE_IN_GAME_PLAYING_H_
#define PCARS_REQUEST_GAME_STATE_IN_GAME_PLAYING_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Game_State_In_Game_Playing : public Request {
public:
	Request_Game_State_In_Game_Playing(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Game_State_In_Game_Playing() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Game_State_In_Game_Playing(const Request_Game_State_In_Game_Playing&) = delete;
	Request_Game_State_In_Game_Playing& operator=(const Request_Game_State_In_Game_Playing&) = delete;
};

}

#endif

