#ifndef PCARS_PROCESS_DATA_H_
#define PCARS_PROCESS_DATA_H_

#include "decodertelemetrydata.h"

namespace pcars { 

class Process {
public:
	using Lap_Data = std::vector<Decoder_Telemetry_Data>;

	virtual ~Process() {}

	virtual void process(const Lap_Data& lap_data) const = 0;
};

class Process_Lap : public Process {
public:
	Process_Lap();
	virtual ~Process_Lap() {}

	void process(const Lap_Data& lap_data) const override;

};

class Process_Track : public Process {
public:
	Process_Track();
	virtual ~Process_Track() {}

	void process(const Lap_Data& lap_data) const override;

};


}

#endif

