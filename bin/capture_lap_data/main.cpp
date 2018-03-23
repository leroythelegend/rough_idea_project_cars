#include "capturetelemetry.h"
#include "process.h"
#include "live.h"

int main() {

	pcars::Process_Decision_Tree decision_tree;
	pcars::Process_Lap process;
	pcars::Live_Feed live;
	pcars::Capture_Telemetry telemetry(&process, &live, &decision_tree);

	return 0;

}
