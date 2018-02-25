#ifndef PCARS_REQUEST_RACE_STATE_NOT_STARTED_H_
#define PCARS_REQUEST_RACE_STATE_NOT_STARTED_H_

#include "request.h"

namespace pcars {

class Request_Race_State_Not_Started : public Request {
public:
	Request_Race_State_Not_Started(Request * request = nullptr);
	virtual ~Request_Race_State_Not_Started() {}

	bool request(Data *) override;

private:
	Request * request_;

	Request_Race_State_Not_Started(const Request_Race_State_Not_Started&) = delete;
	Request_Race_State_Not_Started& operator=(const Request_Race_State_Not_Started&) = delete;
};

}

#endif

