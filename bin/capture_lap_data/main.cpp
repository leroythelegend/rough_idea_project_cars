#include "capturetelemetry.h"
#include "process.h"
#include "live.h"

int main() {

	pcars::Process_Lap process;
	pcars::Live_Feed live;
	pcars::Capture_Telemetry telemetry(&process, &live);

	return 0;

}
