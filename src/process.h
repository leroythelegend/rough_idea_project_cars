#ifndef PCARS_PROCESS_DATA_H_
#define PCARS_PROCESS_DATA_H_

#include <memory>
#include <vector>

#include "decodertelemetrydata.h"
#include "data.h"
#include "packet.h"
#include "decision.h"

namespace pcars { 

class Process {
public:
	using Lap_Data = std::vector<std::shared_ptr<Data> >;

	virtual ~Process() {}

	virtual void process(const Lap_Data) const = 0;
};

class Process_Lap : public Process {
public:
	Process_Lap();
	virtual ~Process_Lap() {}

	void process(const Lap_Data) const override;

};

class Process_Lap_V2 : public Process {
public:
	Process_Lap_V2();
	virtual ~Process_Lap_V2() {}

	void process(const Lap_Data) const override;

};

class Process_Track : public Process {
public:
	Process_Track();
	virtual ~Process_Track() {}

	void process(const Lap_Data) const override;
};

class Process_Session
{
public:
	using Lap_Data = std::vector<std::shared_ptr<Data> >;

	virtual ~Process_Session() {}

	virtual void capture_session(const Lap_Data&) = 0;
	virtual void process_session() = 0;
};

class Process_Decision_Tree : public Process_Session {
public:
	using Decisions = std::vector<std::shared_ptr<Decision> >; 
	using Results = std::vector<std::shared_ptr<Result> >; 

	Process_Decision_Tree();
	virtual ~Process_Decision_Tree() {}

	void capture_session(const Lap_Data&) override;
	void process_session() override;

private:
	Decisions decisions_;
	Results results_;

	Lap_Data lap_data_;
};


}

#endif

