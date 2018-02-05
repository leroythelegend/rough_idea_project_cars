#ifndef PCARS_REQUEST_RACE_STATE_RACING_H_
#define PCARS_REQUEST_RACE_STATE_RACING_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Race_State_Racing : public Request {
public:
	Request_Race_State_Racing(Record_Lap *, Request * request = nullptr);
	virtual ~Request_Race_State_Racing() {}

	bool request(Decoder *) override;

private:
	Record_Lap * record_;
	Request * request_;
	
	Request_Race_State_Racing(const Request_Race_State_Racing&) = delete;
	Request_Race_State_Racing& operator=(const Request_Race_State_Racing&) = delete;
};

}

#endif

