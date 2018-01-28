#ifndef PCARS_REQUEST_TELEMETRY_H_
#define PCARS_REQUEST_TELEMETRY_H_

#include "requestpackage.h"

#include "requestracestateracing.h"

namespace pcars {

class Request_Package_Telemetry : public Request_Package {
public:
	Request_Package_Telemetry(Request_Package * request = NULL);
	virtual ~Request_Package_Telemetry() {}

	bool request(const PCars_Data &) override;

private:
	Request_Package * request_;
	
	Request_Race_State_Racing racing_;
};

}

#endif
