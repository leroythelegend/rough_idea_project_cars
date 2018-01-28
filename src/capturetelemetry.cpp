#include "capturetelemetry.h"

#include "requestpackagetelemetry.h"
#include "transportudp.h"

namespace pcars {

Capture_Telemetry::Capture_Telemetry() 
	: Capture_Telemetry(new Process_Lap) {
}

Capture_Telemetry::Capture_Telemetry(Process * process) {

	Transport_UDP transport(5606);
	Request_Package_Telemetry requester;

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(2048));

	} while (notdone);
}

Capture_Telemetry::Capture_Telemetry(Process * process, Live * live) {

	Transport_UDP transport(5606);
	Request_Package_Telemetry requester;

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(2048));

	} while (notdone);
}

Capture_Telemetry::Capture_Telemetry(Live * live) {

	Transport_UDP transport(5606);
	Request_Package_Telemetry requester;

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(2048));

	} while (notdone);
}

}

