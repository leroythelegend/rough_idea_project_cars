#ifndef PCARS_REQUEST_PIT_MODE_IN_PIT_H_
#define PCARS_REQUEST_PIT_MODE_IN_PIT_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Pit_Mode_In_Pit : public Request {
public:
	Request_Pit_Mode_In_Pit(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Pit_Mode_In_Pit() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

	Request_Pit_Mode_In_Pit(const Request_Pit_Mode_In_Pit&) = delete;
	Request_Pit_Mode_In_Pit& operator=(const Request_Pit_Mode_In_Pit&) = delete;
};

}

#endif

