#ifndef PCARS_REQUEST_RACE_STATE_RETIRED_H_
#define PCARS_REQUEST_RACE_STATE_RETIRED_H_

#include "request.h"

namespace pcars {

class Request_Race_State_Retired : public Request {
public:
	Request_Race_State_Retired(Request * request = nullptr);
	virtual ~Request_Race_State_Retired() {}

	bool request(Data *);

private:
	Request * request_;

	Request_Race_State_Retired(const Request_Race_State_Retired&) = delete;
	Request_Race_State_Retired& operator=(const Request_Race_State_Retired&) = delete;
};

}

#endif
