#ifndef PCARS_REQUEST_GAME_STATE_IN_MENU_TIME_TICKING_H_
#define PCARS_REQUEST_GAME_STATE_IN_MENU_TIME_TICKING_H_

#include "request.h"

namespace pcars {

class Request_Game_State_In_Game_Menu_Time_Ticking : public Request {
public:
	Request_Game_State_In_Game_Menu_Time_Ticking(Request *);
	virtual ~Request_Game_State_In_Game_Menu_Time_Ticking() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Request * request_;
};

}

#endif

