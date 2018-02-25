#ifndef PCARS_REQUEST_SESSION_STATE_RACE_V2_H_
#define PCARS_REQUEST_SESSION_STATE_RACE_V2_H_

#include "request.h"

#include "recordlap.h"
#include "requestracestateracingv2.h"

namespace pcars {

class Request_Session_State_Race_V2 : public Request {
public:
	Request_Session_State_Race_V2(Record_Lap *, Request * request = nullptr);
	virtual ~Request_Session_State_Race_V2() {}

	bool request(Data *) override;

private:
	Request * request_;

	Request_Race_State_Racing_V2 racing_;

	Request_Session_State_Race_V2(const Request_Session_State_Race_V2&) = delete;
	Request_Session_State_Race_V2& operator=(const Request_Session_State_Race_V2&) = delete;
};

}

#endif

