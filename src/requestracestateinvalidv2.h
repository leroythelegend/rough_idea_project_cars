#ifndef PCARS_REQUEST_RACE_STATE_INVALID_V2_H_
#define PCARS_REQUEST_RACE_STATE_INVALID_V2_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Race_State_Invalid_V2 : public Request {
public:
	Request_Race_State_Invalid_V2(Record_Lap *, Request * request = nullptr);
	virtual ~Request_Race_State_Invalid_V2() {}

	bool request(Decoder *) override;

private:
	Record_Lap * record_;
	Request * request_;
	
	Request_Race_State_Invalid_V2(const Request_Race_State_Invalid_V2&) = delete;
	Request_Race_State_Invalid_V2& operator=(const Request_Race_State_Invalid_V2&) = delete;
};

}

#endif

