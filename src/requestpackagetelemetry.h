#ifndef PCARS_REQUEST_TELEMETRY_H_
#define PCARS_REQUEST_TELEMETRY_H_

#include "requestpackage.h"

#include "requestsessionstatepractice.h"
#include "requestsessionstatequalify.h"
#include "requestsessionstaterace.h"

namespace pcars {

class Request_Package_Telemetry : public Request_Package {
public:
	Request_Package_Telemetry(Request_Package * request = NULL);
	virtual ~Request_Package_Telemetry() {}

	bool request(const PCars_Data &) override;

private:
	Request_Package * request_;

	Process_Lap process_;
	Record_Post_Lap record_;	

	Request_Session_State_Practice practice_;
	Request_Session_State_Qualify  qualy_;
	Request_Session_State_Race     race_;
};

}

#endif
