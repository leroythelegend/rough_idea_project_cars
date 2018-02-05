#ifndef PCARS_REQUEST_TELEMETRY_V2_H_
#define PCARS_REQUEST_TELEMETRY_V2_H_

#include "requestpackage.h"

#include "packet.h"
#include "requestsessionstatepracticev2.h"
#include "requestsessionstateracev2.h"
#include "requestsessionstatequalifyv2.h"
#include "recordlap.h"


namespace pcars {

class Request_Package_Telemetry_V2 : public Request_Package {
public:
	Request_Package_Telemetry_V2(Process *, Live *);
	virtual ~Request_Package_Telemetry_V2() {}

	bool request(const PCars_Data &) override;

private:

	Packet packet_;

	Record_Post_Lap_V2 recordlap_;	
	Record_Live_Data recordlive_;

	Request_Session_State_Practice_V2 practice_;
	Request_Session_State_Qualify_V2 qualy_;
	Request_Session_State_Race_V2 race_;
};

}

#endif

