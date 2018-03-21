#ifndef PCARS_REQUEST_RACE_STATE_FINISHED_H_
#define PCARS_REQUEST_RACE_STATE_FINISHED_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Race_State_Finished : public Request {
public:
	Request_Race_State_Finished(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Race_State_Finished() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Race_State_Finished(const Request_Race_State_Finished&) = delete;
	Request_Race_State_Finished& operator=(const Request_Race_State_Finished&) = delete;
};

}

#endif

