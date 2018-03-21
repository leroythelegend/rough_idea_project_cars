#ifndef PCARS_REQUEST_RACE_STATE_RETIRED_H_
#define PCARS_REQUEST_RACE_STATE_RETIRED_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Race_State_Retired : public Request {
public:
	Request_Race_State_Retired(Record_Lap * = nullptr, Request * request = nullptr);
	virtual ~Request_Race_State_Retired() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Race_State_Retired(const Request_Race_State_Retired&) = delete;
	Request_Race_State_Retired& operator=(const Request_Race_State_Retired&) = delete;
};

}

#endif
