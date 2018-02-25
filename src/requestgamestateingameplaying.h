#ifndef PCARS_REQUEST_GAME_STATE_IN_GAME_PLAYING_H_
#define PCARS_REQUEST_GAME_STATE_IN_GAME_PLAYING_H_

#include "request.h"

#include "requestsessionstateinvalid.h"
#include "requestsessionstatepractice.h"
#include "requestsessionstatetest.h"
#include "requestsessionstatequalify.h"
#include "requestsessionstateformationlap.h"
#include "requestsessionstaterace.h"
#include "requestsessionstatetimeattack.h"

namespace pcars {

class Request_Game_State_In_Game_Playing : public Request {
public:
	Request_Game_State_In_Game_Playing(Request * request = nullptr);
	virtual ~Request_Game_State_In_Game_Playing() {}

	bool request(Data *) override;

private:
	Request * request_;

	Request_Game_State_In_Game_Playing(const Request_Game_State_In_Game_Playing&) = delete;
	Request_Game_State_In_Game_Playing& operator=(const Request_Game_State_In_Game_Playing&) = delete;
};

}

#endif

