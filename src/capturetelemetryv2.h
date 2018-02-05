#ifndef PCARS_CAPTURE_TELEMETRY_V2_H_
#define PCARS_CAPTURE_TELEMETRY_V2_H_

#include <memory>

#include "process.h"
#include "live.h"

namespace pcars {

class Capture_Telemetry_V2 {
public:
	Capture_Telemetry_V2(Process *, Live *);
};

}

#endif

