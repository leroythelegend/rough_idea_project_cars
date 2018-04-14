#include "capturetelemetry.h"
#include "process.h"
#include "live.h"

int main() {

	pcars::Process_Decision_Tree decision_tree;
	pcars::Process_Track track;
	pcars::Live_Feed live;
	pcars::Capture_Telemetry telemetry(&track, &live, &decision_tree);

	return 0;

}
