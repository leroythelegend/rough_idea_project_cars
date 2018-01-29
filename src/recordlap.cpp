#include "recordlap.h"

#include <iostream>
#include <thread>

#include "process.h"
#include "capturetelemetry.h"

using namespace std;

namespace pcars {

std::mutex global_mutex_;

class Thread_Args 
{
public:
	Thread_Args(Process * process, Process::Lap_Data data)
		: process_(process),
		  data_(data) {}
	
	Process * process_;
	Process::Lap_Data data_;
};

void process_func(const Thread_Args args) {
	unique_lock<mutex> lck(global_mutex_);
	args.process_->process(args.data_);
};

Record_Post_Lap::Record_Post_Lap(Process * process)
	: process_{process},
	  lap_number_{-1}
{
}

void Record_Post_Lap::record(Decoder * decoder)
{
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);
	if (tdecoder) {
		if (lap_number_ != static_cast<int>(tdecoder->participant_info().at(0).current_lap())) {
			lap_number_ = tdecoder->participant_info().at(0).current_lap();
			if (lap_data_.size()) {

				thread t(process_func, Thread_Args(process_, lap_data_));
				t.detach();

				lap_data_.clear();
				lap_data_.push_back(*tdecoder);
			}
			else {
					lap_data_.push_back(*tdecoder);
			}
		}
		else {
			lap_data_.push_back(*tdecoder);
		}
	}
}

Record_Live_Data::Record_Live_Data(Live * live) 
	: live_{live} {}

void Record_Live_Data::record(Decoder * decoder)
{
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);
	if (tdecoder) {
		live_->live(tdecoder);
	}
}


}

