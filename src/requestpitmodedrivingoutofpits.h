#ifndef PCARS_PIT_MODE_DRIVING_OUT_OF_PITS_H_
#define PCARS_PIT_MODE_DRIVING_OUT_OF_PITS_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Pit_Mode_Driving_Out_Of_Pits : public Request {
public:
	Request_Pit_Mode_Driving_Out_Of_Pits(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Pit_Mode_Driving_Out_Of_Pits() {}

	bool request(std::shared_ptr<Data>);

private:
	Record_Lap * record_;
	Request * request_;

	Request_Pit_Mode_Driving_Out_Of_Pits(const Request_Pit_Mode_Driving_Out_Of_Pits&) = delete;
	Request_Pit_Mode_Driving_Out_Of_Pits& operator=(const Request_Pit_Mode_Driving_Out_Of_Pits&) = delete;
};

}

#endif

