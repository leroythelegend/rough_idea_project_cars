#ifndef PCARS_REQUEST_SESSION_STATE_TEST_H_
#define PCARS_REQUEST_SESSION_STATE_TEST_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Session_State_Test : public Request {
public:
	Request_Session_State_Test(Record_Lap * = nullptr, Request * request = nullptr);
	virtual ~Request_Session_State_Test() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Session_State_Test(const Request_Session_State_Test&) = delete;
	Request_Session_State_Test& operator=(const Request_Session_State_Test&) = delete;
};

}

#endif

