#include "capturetelemetry.h"

#include "requestpackagetelemetry.h"
#include "transportudp.h"

namespace pcars {

Process * global_process_lap;
Live * global_live_lap;

Capture_Telemetry::Capture_Telemetry() 
	: Capture_Telemetry(new Process_Lap) {
}

Capture_Telemetry::Capture_Telemetry(Process * process) {
	global_process_lap = process;
	global_live_lap = nullptr;

	Transport_UDP transport(5606);
	Request_Package_Telemetry requester;

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(2048));

	} while (notdone);
}

Capture_Telemetry::Capture_Telemetry(Process * process, Live * live) {
	global_process_lap = process;
	global_live_lap = live;

	Transport_UDP transport(5606);
	Request_Package_Telemetry requester;

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(2048));

	} while (notdone);
}

Capture_Telemetry::Capture_Telemetry(Live * live) {
	global_process_lap = nullptr;
	global_live_lap = live;

	Transport_UDP transport(5606);
	Request_Package_Telemetry requester;

	bool notdone = true;
	do {
		notdone = requester.request(transport.read(2048));

	} while (notdone);
}
}

