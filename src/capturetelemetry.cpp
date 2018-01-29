#include "capturetelemetry.h"

#include "requestpackagetelemetry.h"
#include "transportudp.h"

namespace pcars {

Capture_Telemetry::Capture_Telemetry(Process * process, Live * live) {

	Transport_UDP transport(5606);
	Request_Package_Telemetry requester(process, live);

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(2048));

	} while (notdone);
}

}

