#ifndef PCARS_REQUEST_TELEMETRY_H_
#define PCARS_REQUEST_TELEMETRY_H_

#include "requestpackage.h"

#include "requestsessionstatepractice.h"
#include "requestsessionstatequalify.h"
#include "requestsessionstaterace.h"
#include "requestracestateracing.h"
#include "requestpitmodeingarage.h"

namespace pcars {

class Request_Package_Telemetry : public Request_Package {
public:
	Request_Package_Telemetry(Process *, Live *, Process_Session *);
	virtual ~Request_Package_Telemetry() {}

	bool request(const PCars_Data &) override;

private:
	Record_Post_Lap post_lap_;	
	Record_Live_Data live_;

	Record_Session session_;
	Record_Session_Result session_result_;

	Request_Race_State_Racing race_racing_;
	Request_Session_State_Race race_;

	Request_Race_State_Racing qualy_racing_;
	Request_Session_State_Qualify  qualy_;

	Request_Race_State_Racing practice_racing_;
	Request_Session_State_Practice practice_;

	Request_Race_State_Racing practice_racing_live_;
	Request_Session_State_Practice practice_live_;

	Request_Race_State_Racing practice_capture_decision_;
	Request_Session_State_Practice pracitice_decision_;

	Request_Pit_Mode_In_Garage pracitice_decision_result_;
	Request_Session_State_Practice pracitice_result_;
};

}

#endif
