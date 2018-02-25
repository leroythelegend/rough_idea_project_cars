#ifndef PCAR_REQUEST_SSESSION_STATE_FORMATION_LAP_H_
#define PCAR_REQUEST_SSESSION_STATE_FORMATION_LAP_H_

#include "request.h"

namespace pcars {

class Request_Session_State_Formation_Lap : public Request {
public:
	Request_Session_State_Formation_Lap(Request * request = nullptr);
	virtual ~Request_Session_State_Formation_Lap() {}

	bool request(Data *) override;

private:
	Request * request_;

	Request_Session_State_Formation_Lap(const Request_Session_State_Formation_Lap&) = delete;
	Request_Session_State_Formation_Lap& operator=(const Request_Session_State_Formation_Lap&) = delete;
};

}

#endif
