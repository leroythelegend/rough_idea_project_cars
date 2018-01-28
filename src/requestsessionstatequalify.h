#ifndef PCARS_REQUEST_SESSION_STATE_QUALIFY_H_
#define PCARS_REQUEST_SESSION_STATE_QUALIFY_H_

#include "request.h"

#include "requestracestateracing.h"

namespace pcars {

class Request_Session_State_Qualify : public Request {
public:
	Request_Session_State_Qualify(Request * request = nullptr);
	virtual ~Request_Session_State_Qualify() {}

	bool request(Decoder *) override;

private:
	Request * request_;

	Request_Session_State_Qualify(const Request_Session_State_Qualify&) = delete;
	Request_Session_State_Qualify& operator=(const Request_Session_State_Qualify&) = delete;
};


}

#endif
