#ifndef PCARS_REQUEST_PIT_MODE_IN_PIT_H_
#define PCARS_REQUEST_PIT_MODE_IN_PIT_H_

#include "request.h"

namespace pcars {

class Request_Pit_Mode_In_Pit : public Request {
public:
	Request_Pit_Mode_In_Pit(Request * request = nullptr);
	virtual ~Request_Pit_Mode_In_Pit() {}

	bool request(Decoder *) override;

private:
	Request * request_;

	Request_Pit_Mode_In_Pit(const Request_Pit_Mode_In_Pit&) = delete;
	Request_Pit_Mode_In_Pit& operator=(const Request_Pit_Mode_In_Pit&) = delete;
};

}

#endif

