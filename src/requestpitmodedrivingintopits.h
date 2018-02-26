#ifndef PCARS_REQUEST_PIT_MODE_DRIVING_INTO_PITS_H_
#define PCARS_REQUEST_PIT_MODE_DRIVING_INTO_PITS_H_

#include "request.h"

namespace pcars {

class Request_Pit_Mode_Driving_Into_Pits : public Request {
public:
	Request_Pit_Mode_Driving_Into_Pits(Request * request = nullptr);
	virtual ~Request_Pit_Mode_Driving_Into_Pits() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Request * request_;

	Request_Pit_Mode_Driving_Into_Pits(const Request_Pit_Mode_Driving_Into_Pits&) = delete;
	Request_Pit_Mode_Driving_Into_Pits& operator=(const Request_Pit_Mode_Driving_Into_Pits&) = delete;
};

}

#endif

