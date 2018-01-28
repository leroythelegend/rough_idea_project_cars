#ifndef PCARS_REQUEST_SESSION_STATE_INVALID_H_
#define PCARS_REQUEST_SESSION_STATE_INVALID_H_

#include "request.h"

namespace pcars {

class Request_Session_State_Invalid : public Request {
public:
	Request_Session_State_Invalid(Request * request = nullptr);
	virtual ~Request_Session_State_Invalid() {}

	bool request(Decoder *) override;

private:
	Request * request_;

	Request_Session_State_Invalid(const Request_Session_State_Invalid&) = delete;
	Request_Session_State_Invalid& operator=(const Request_Session_State_Invalid&) = delete;
};

}

#endif
