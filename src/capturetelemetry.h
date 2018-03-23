#ifndef PCARS_CAPTURE_TELEMETRY_H_
#define PCARS_CAPTURE_TELEMETRY_H_

#include <memory>

#include "process.h"
#include "live.h"

namespace pcars {

class Capture_Telemetry {
public:
	Capture_Telemetry(Process *, Live *, Process_Session *);
};

}

#endif

