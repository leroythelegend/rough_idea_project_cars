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

	virtual ~Record_Lap() {};

	virtual	void record(Decoder *) = 0;
};

class Record_Post_Lap : public Record_Lap
{
public:
	using Vector_Lap_Telemetry = std::vector<Decoder_Telemetry_Data>;

	Record_Post_Lap();
	virtual ~Record_Post_Lap() {};

	void record(Decoder *) override;

private:
	Lap_Number lap_number_;
	Vector_Lap_Telemetry lap_data_;
};


}

#endif

