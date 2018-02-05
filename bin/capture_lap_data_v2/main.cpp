#include "capturetelemetryv2.h"
#include "process.h"
#include "live.h"

int main() {

	pcars::Process_Lap process;
	pcars::Live_Feed_V2 live;
	pcars::Capture_Telemetry_V2 telemetry(&process, &live);

	return 0;

}
