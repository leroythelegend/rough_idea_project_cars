#ifndef PCARS_REQUEST_TELEMETRY_H_
#define PCARS_REQUEST_TELEMETRY_H_

#include "requestpackage.h"

#include "requestsessionstatepractice.h"
#include "requestsessionstatequalify.h"
#include "requestsessionstaterace.h"

namespace pcars {

class Request_Package_Telemetry : public Request_Package {
public:
	Request_Package_Telemetry(Process *, Live *, Request_Package * request = NULL);
	virtual ~Request_Package_Telemetry() {}

	bool request(const PCars_Data &) override;

private:
	Request_Package * request_;

	Record_Post_Lap recordlap_;	
	Record_Live_Data recordlive_;

	Request_Session_State_Practice practice_;
	Request_Session_State_Qualify  qualy_;
	Request_Session_State_Race     race_;
};

}

#endif
