#ifndef PCARS_REQUEST_GAME_STATE_EXIT_V2_H_
#define PCARS_REQUEST_GAME_STATE_EXIT_V2_H_

#include "request.h"

namespace pcars {

class Request_Game_State_Exit_V2 : public Request {
public:
	Request_Game_State_Exit_V2(Request *);
	virtual ~Request_Game_State_Exit_V2() {}

	bool request(Decoder *) override;

private:
	Request * request_;
};

}

#endif

