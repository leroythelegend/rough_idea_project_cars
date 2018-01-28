#ifndef PCARS_REQUEST_SESSION_STATE_TEST_H_
#define PCARS_REQUEST_SESSION_STATE_TEST_H_

#include "request.h"

#include "requestracestateracing.h"

namespace pcars {

class Request_Session_State_Test : public Request {
public:
	Request_Session_State_Test(Request * request = nullptr);
	virtual ~Request_Session_State_Test() {}

	bool request(Decoder *) override;

private:
	Request * request_;

	Request_Session_State_Test(const Request_Session_State_Test&) = delete;
	Request_Session_State_Test& operator=(const Request_Session_State_Test&) = delete;
};

}

#endif

