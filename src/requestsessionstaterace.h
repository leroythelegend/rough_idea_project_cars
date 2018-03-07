#ifndef PCARS_REQUEST_SESSION_STATE_RACE_H_
#define PCARS_REQUEST_SESSION_STATE_RACE_H_

#include "request.h"

#include "requestracestateracing.h"
#include "recordlap.h"

namespace pcars {

class Request_Session_State_Race : public Request {
public:
	Request_Session_State_Race(Record_Lap *, Request * request = nullptr);
	virtual ~Request_Session_State_Race() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Request * request_;

	Request_Race_State_Racing racing_;

	Request_Session_State_Race(const Request_Session_State_Race&) = delete;
	Request_Session_State_Race& operator=(const Request_Session_State_Race&) = delete;
};

}

#endif
