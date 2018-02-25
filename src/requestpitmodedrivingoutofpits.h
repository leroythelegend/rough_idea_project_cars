#ifndef PCARS_PIT_MODE_DRIVING_OUT_OF_PITS_H_
#define PCARS_PIT_MODE_DRIVING_OUT_OF_PITS_H_

#include "request.h"

namespace pcars {

class Request_Pit_Mode_Driving_Out_Of_Pits : public Request {
public:
	Request_Pit_Mode_Driving_Out_Of_Pits(Request * request = nullptr);
	virtual ~Request_Pit_Mode_Driving_Out_Of_Pits() {}

	bool request(Data *);

private:
	Request * request_;

	Request_Pit_Mode_Driving_Out_Of_Pits(const Request_Pit_Mode_Driving_Out_Of_Pits&) = delete;
	Request_Pit_Mode_Driving_Out_Of_Pits& operator=(const Request_Pit_Mode_Driving_Out_Of_Pits&) = delete;
};

}

#endif

