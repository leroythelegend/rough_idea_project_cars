#include "capturetelemetryv2.h"
#include "process.h"
#include "live.h"

int main() {

	pcars::Process_Lap_V2 process;
	pcars::Live_Feed live;
	pcars::Capture_Telemetry_V2 telemetry(&process, &live);

	return 0;

}
