#ifndef PCARS_RECORD_LAP_H_
#define PCARS_RECORD_LAP_H_

#include <memory>
#include <vector>
#include <thread>

#include "decodertelemetrydata.h"
#include "process.h"

namespace pcars {

class Record_Lap 
{
public:
	using Vector_Lap_Telemetry = std::vector<Decoder_Telemetry_Data>;

	Record_Lap();
	virtual ~Record_Lap() {};

	void record(Decoder *);
	void clear(); 

private:
	Lap_Number lap_number_;
	Vector_Lap_Telemetry lap_data_;
};

}

#endif

