#ifndef PCARS_REQUEST_PIT_MODE_NONE_H_
#define PCARS_REQUEST_PIT_MODE_NONE_H_

#include "request.h"

namespace pcars {

class Request_Pit_Mode_None : public Request {
public:
	Request_Pit_Mode_None(Request * request = nullptr);
	virtual ~Request_Pit_Mode_None() {}

	bool request(Data *) override;

private:
	Request * request_;

	Request_Pit_Mode_None(const Request_Pit_Mode_None&) = delete;
	Request_Pit_Mode_None& operator=(const Request_Pit_Mode_None&) = delete;
};

}

#endif

