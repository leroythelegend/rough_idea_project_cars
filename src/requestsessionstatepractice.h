#ifndef PCARS_REQUEST_SESSION_STATE_PRACTICE_H_
#define PCARS_REQUEST_SESSION_STATE_PRACTICE_H_

#include "request.h"

#include "recordlap.h"
#include "requestracestateracing.h"

namespace pcars {

class Request_Session_State_Practice : public Request {
public:
	Request_Session_State_Practice(Record_Lap *, Request * request = nullptr);
	virtual ~Request_Session_State_Practice() {}

	bool request(Decoder *) override;

private:
	Request * request_;

	Request_Race_State_Racing racing_;

	Request_Session_State_Practice(const Request_Session_State_Practice&) = delete;
	Request_Session_State_Practice& operator=(const Request_Session_State_Practice&) = delete;
};

}

#endif
