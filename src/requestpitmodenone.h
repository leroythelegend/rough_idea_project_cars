#ifndef PCARS_REQUEST_PIT_MODE_NONE_H_
#define PCARS_REQUEST_PIT_MODE_NONE_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Pit_Mode_None : public Request {
public:
	Request_Pit_Mode_None(Record_Lap * = nullptr, Request * request = nullptr);
	virtual ~Request_Pit_Mode_None() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Pit_Mode_None(const Request_Pit_Mode_None&) = delete;
	Request_Pit_Mode_None& operator=(const Request_Pit_Mode_None&) = delete;
};

}

#endif

