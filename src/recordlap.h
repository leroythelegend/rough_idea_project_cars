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

	virtual	void record(std::shared_ptr<Data>) = 0;
};

class Record_Post_Lap : public Record_Lap
{
public:
	using Vector_Lap_Data = std::vector<std::shared_ptr<Data> >;

	Record_Post_Lap(Process *);
	virtual ~Record_Post_Lap() {};

	void record(std::shared_ptr<Data>) override;

private:
	Process * process_;
	Lap_Number lap_number_;
	Vector_Lap_Data lap_data_;
};

class Record_Live_Data : public Record_Lap
{
public:
	Record_Live_Data(Live *);
	virtual ~Record_Live_Data() {};

	void record(std::shared_ptr<Data>) override;

private:
	Live * live_;
};

class Record_Session : public Record_Lap
{
public:
	using Vector_Lap_Data = std::vector<std::shared_ptr<Data> >;

	Record_Session(Process_Session *);
	virtual ~Record_Session() {};

	void record(std::shared_ptr<Data>) override;

private:
	Process_Session * process_;
	Lap_Number lap_number_;
	Vector_Lap_Data lap_data_;
};


class Record_Session_Result : public Record_Lap
{
public:
	Record_Session_Result(Process_Session *);
	virtual ~Record_Session_Result() {};

	void record(std::shared_ptr<Data>) override;

private:
	Process_Session * process_;
};


}

#endif

