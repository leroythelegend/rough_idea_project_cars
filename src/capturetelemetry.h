#ifndef PCARS_CAPTURE_TELEMETRY_H_
#define PCARS_CAPTURE_TELEMETRY_H_

#include <memory>

#include "process.h"
#include "live.h"

namespace pcars {

class Capture_Telemetry {
public:
	Capture_Telemetry();
	Capture_Telemetry(Process *);
	Capture_Telemetry(Process *, Live *);
	Capture_Telemetry(Live *);
};

}

#endif

