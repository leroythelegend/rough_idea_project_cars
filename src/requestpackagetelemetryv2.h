#ifndef PCARS_REQUEST_TELEMETRY_V2_H_
#define PCARS_REQUEST_TELEMETRY_V2_H_

#include "requestpackage.h"

#include "packet.h"
#include "requestsessionstatepractice.h"
#include "requestsessionstaterace.h"
#include "requestsessionstatequalify.h"
#include "recordlap.h"


namespace pcars {

class Request_Package_Telemetry_V2 : public Request_Package {
public:
	Request_Package_Telemetry_V2(Process *, Live *);
	virtual ~Request_Package_Telemetry_V2() {}

	bool request(const PCars_Data &) override;

private:

	Packet packet_;

	Record_Post_Lap  recordlap_;	
	Record_Live_Data recordlive_;

	Request_Session_State_Practice practice_;
	Request_Session_State_Qualify qualy_;
	Request_Session_State_Race race_;
};

}

#endif

