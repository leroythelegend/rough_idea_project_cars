#ifndef PCARS_REQUEST_TELEMETRY_V2_H_
#define PCARS_REQUEST_TELEMETRY_V2_H_

#include "requestpackage.h"

#include "packet.h"

#include "requestsessionstatepractice.h"
#include "requestsessionstatequalify.h"
#include "requestsessionstaterace.h"
#include "requestracestateracing.h"
#include "requestpitmodeingarage.h"
#include "requestpitmodenone.h"

namespace pcars {

class Request_Package_Telemetry_V2 : public Request_Package {
public:
	Request_Package_Telemetry_V2(Process *, Live *, Process_Session *);
	virtual ~Request_Package_Telemetry_V2() {}

	bool request(const PCars_Data &) override;

private:

	Packet packet_;

	Record_Post_Lap post_lap_;	
	Record_Live_Data live_;

	Record_Session session_;
	Record_Session_Result session_result_;

	Request_Pit_Mode_None race_not_in_pits_;
	Request_Session_State_Race race_;

	Request_Pit_Mode_None qualy_not_in_pits_;
	Request_Session_State_Qualify  qualy_;

	Request_Race_State_Racing practice_racing_;
	Request_Session_State_Practice practice_;

	Request_Pit_Mode_None practice_not_in_pits_;
	Request_Session_State_Practice practice_live_;

	Request_Race_State_Racing practice_capture_decision_;
	Request_Session_State_Practice pracitice_decision_;

	Request_Pit_Mode_In_Garage pracitice_decision_result_;
	Request_Session_State_Practice pracitice_result_;
};

}

#endif

