#ifndef PCARS_RECORD_LAP_H_
#define PCARS_RECORD_LAP_H_

#include <memory>
#include <vector>
#include <thread>

#include "decodertelemetrydata.h"
#include "process.h"
#include "live.h"

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

	Record_Post_Lap(Process *);
	virtual ~Record_Post_Lap() {};

	void record(Decoder *) override;

private:
	Process * process_;
	Lap_Number lap_number_;
	Vector_Lap_Telemetry lap_data_;
};

class Record_Live_Data : public Record_Lap
{
public:
	Record_Live_Data(Live *);
	virtual ~Record_Live_Data() {};

	void record(Decoder *) override;

private:
	Live * live_;
};


}

#endif

