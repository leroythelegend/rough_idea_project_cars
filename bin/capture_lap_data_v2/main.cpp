#include "capturetelemetryv2.h"
#include "process.h"
#include "live.h"

int main() {
 
	pcars::Process_Decision_Tree decision_tree; 
	pcars::Process_Lap_V2 process; 
	pcars::Live_Feed live; 
	pcars::Capture_Telemetry_V2 telemetry(&process, &live, &decision_tree); 

        return 0; 
}
