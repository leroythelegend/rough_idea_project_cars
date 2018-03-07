#ifndef PCARS_REQUEST_RACE_STATE_DISQUALIFIED_H_
#define PCARS_REQUEST_RACE_STATE_DISQUALIFIED_H_

#include "request.h"

namespace pcars {

class Request_Race_State_Disqualified : public Request {
public:
	Request_Race_State_Disqualified(Request * request = nullptr);
	virtual ~Request_Race_State_Disqualified() {}

	bool request(std::shared_ptr<Data>);

private:
	Request * request_;

	Request_Race_State_Disqualified(const Request_Race_State_Disqualified&);
	Request_Race_State_Disqualified& operator=(const Request_Race_State_Disqualified&);
};

}

#endif

