#include "capturetelemetry.h"
#include "process.h"
#include "live.h"

int main() {

	pcars::Process_Track track;
	pcars::Live_Feed live;
	pcars::Capture_Telemetry telemetry(&track, &live);

	return 0;

}
