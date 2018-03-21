#ifndef PCARS_REQUEST_TELEMETRY_H_
#define PCARS_REQUEST_TELEMETRY_H_

#include "requestpackage.h"

#include "requestsessionstatepractice.h"
#include "requestsessionstatequalify.h"
#include "requestsessionstaterace.h"
#include "requestracestateracing.h"

namespace pcars {

class Request_Package_Telemetry : public Request_Package {
public:
	Request_Package_Telemetry(Process *, Live *);
	virtual ~Request_Package_Telemetry() {}

	bool request(const PCars_Data &) override;

private:
	Record_Post_Lap post_lap_;	
	Record_Live_Data live_;

	Request_Race_State_Racing race_racing_;
	Request_Session_State_Race race_;
	Request_Race_State_Racing qualy_racing_;
	Request_Session_State_Qualify  qualy_;
	Request_Race_State_Racing practice_racing_;
	Request_Session_State_Practice practice_;

};

}

#endif
