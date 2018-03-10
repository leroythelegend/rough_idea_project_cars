#ifndef PCARS_REQUEST_RACE_STATE_NOT_STARTED_H_
#define PCARS_REQUEST_RACE_STATE_NOT_STARTED_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Race_State_Not_Started : public Request {
public:
	Request_Race_State_Not_Started(Record_Lap *, Request * request = nullptr);
	virtual ~Request_Race_State_Not_Started() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Race_State_Not_Started(const Request_Race_State_Not_Started&) = delete;
	Request_Race_State_Not_Started& operator=(const Request_Race_State_Not_Started&) = delete;
};

}

#endif

