#include "capturetelemetryv2.h"

#include <iostream>

#include "requestpackagetelemetryv2.h"
#include "transportudp.h"

namespace pcars {

Capture_Telemetry_V2::Capture_Telemetry_V2(Process * process, Live * live, Process_Session * session) {

	Transport_UDP transport(5606);
	Request_Package_Telemetry_V2 requester(process, live, session);

	std::cout << "Started" << std::endl;

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(1500));

	} while (notdone);
}


}

