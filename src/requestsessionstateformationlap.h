#ifndef PCAR_REQUEST_SSESSION_STATE_FORMATION_LAP_H_
#define PCAR_REQUEST_SSESSION_STATE_FORMATION_LAP_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Session_State_Formation_Lap : public Request {
public:
	Request_Session_State_Formation_Lap(Record_Lap * = nullptr, Request * request = nullptr);
	virtual ~Request_Session_State_Formation_Lap() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Session_State_Formation_Lap(const Request_Session_State_Formation_Lap&) = delete;
	Request_Session_State_Formation_Lap& operator=(const Request_Session_State_Formation_Lap&) = delete;
};

}

#endif
