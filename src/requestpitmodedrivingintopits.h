#ifndef PCARS_REQUEST_PIT_MODE_DRIVING_INTO_PITS_H_
#define PCARS_REQUEST_PIT_MODE_DRIVING_INTO_PITS_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Pit_Mode_Driving_Into_Pits : public Request {
public:
	Request_Pit_Mode_Driving_Into_Pits(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Pit_Mode_Driving_Into_Pits() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Pit_Mode_Driving_Into_Pits(const Request_Pit_Mode_Driving_Into_Pits&) = delete;
	Request_Pit_Mode_Driving_Into_Pits& operator=(const Request_Pit_Mode_Driving_Into_Pits&) = delete;
};

}

#endif

