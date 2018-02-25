#ifndef PCARS_REQUEST_SESSION_STATE_TIME_ATTACK_H_
#define PCARS_REQUEST_SESSION_STATE_TIME_ATTACK_H_

#include "request.h"

namespace pcars {

class Request_Session_State_Time_Attack : public Request {
public:
	Request_Session_State_Time_Attack(Request * request = nullptr);
	virtual ~Request_Session_State_Time_Attack() {}

	bool request(Data *) override;

private:
	Request * request_;

	Request_Session_State_Time_Attack(const Request_Session_State_Time_Attack&) = delete;
	Request_Session_State_Time_Attack& operator=(const Request_Session_State_Time_Attack&) = delete;
};

}

#endif
