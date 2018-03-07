#ifndef PCARS_REQUEST_RACE_STATE_INVALID_H_
#define PCARS_REQUEST_RACE_STATE_INVALID_H_

#include "request.h"

namespace pcars {

class Request_Race_State_Invalid : public Request {
public:
	Request_Race_State_Invalid(Request * request = nullptr);
	virtual ~Request_Race_State_Invalid() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Request * request_;

	Request_Race_State_Invalid(const Request_Race_State_Invalid&) = delete;
	Request_Race_State_Invalid& operator=(const Request_Race_State_Invalid&) = delete;
};

}

#endif

