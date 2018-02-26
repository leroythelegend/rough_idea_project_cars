#ifndef PCARS_RECORD_LAP_H_
#define PCARS_RECORD_LAP_H_

#include <memory>
#include <vector>
#include <thread>

#include "decodertelemetrydata.h"
#include "packet.h"
#include "data.h"
#include "process.h"
#include "live.h"

namespace pcars {

class Record_Lap 
{
public:

	virtual ~Record_Lap() {};

	virtual	void record(Decoder *) = 0;
	virtual	void record(std::shared_ptr<Data>) = 0;
};

class Record_Post_Lap : public Record_Lap
{
public:
	using Vector_Lap_Data = std::vector<std::shared_ptr<Data> >;

	Record_Post_Lap(Process *);
	virtual ~Record_Post_Lap() {};

	void record(Decoder *) override;
	void record(std::shared_ptr<Data>) override;

private:
	Process * process_;
	Lap_Number lap_number_;
	Vector_Lap_Data lap_data_;
};

class Record_Post_Lap_V2 : public Record_Lap
{
public:
	using Vector_Lap_Telemetry = std::vector<Packet>;

	Record_Post_Lap_V2(Process *);
	virtual ~Record_Post_Lap_V2() {};

	void record(Decoder *) override;
	void record(std::shared_ptr<Data>) override {};

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
	void record(std::shared_ptr<Data>) override;

private:
	Live * live_;
};



}

#endif

