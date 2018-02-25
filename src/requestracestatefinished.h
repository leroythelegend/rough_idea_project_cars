#ifndef PCARS_REQUEST_RACE_STATE_FINISHED_H_
#define PCARS_REQUEST_RACE_STATE_FINISHED_H_

#include "request.h"

namespace pcars {

class Request_Race_State_Finished : public Request {
public:
	Request_Race_State_Finished(Request * request);
	virtual ~Request_Race_State_Finished() {}

	bool request(Data *) override;

private:
	Request * request_;

	Request_Race_State_Finished(const Request_Race_State_Finished&) = delete;
	Request_Race_State_Finished& operator=(const Request_Race_State_Finished&) = delete;
};

}

#endif

