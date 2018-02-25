#ifndef PCARS_REQUEST_GAME_STATE_IN_MENU_TIME_TICKING_V2_H_
#define PCARS_REQUEST_GAME_STATE_IN_MENU_TIME_TICKING_V2_H_

#include "request.h"

namespace pcars {

class Request_Game_State_In_Game_Menu_Time_Ticking_V2 : public Request {
public:
	Request_Game_State_In_Game_Menu_Time_Ticking_V2(Request *);
	virtual ~Request_Game_State_In_Game_Menu_Time_Ticking_V2() {}

	bool request(Data *) override;

private:
	Request * request_;
};

}

#endif

