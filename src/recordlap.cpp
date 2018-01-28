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

void process_func(const Process::Lap_Data data) {
	unique_lock<mutex> lck(global_mutex_);
	global_process_lap->process(data);
};

Record_Post_Lap::Record_Post_Lap()
	: lap_number_{-1}
{
}

void Record_Post_Lap::record(Decoder * decoder)
{
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);
	if (tdecoder) {
		if (lap_number_ != static_cast<int>(tdecoder->participant_info().at(0).current_lap())) {
			if (global_process_lap) {
				lap_number_ = tdecoder->participant_info().at(0).current_lap();
				if (lap_data_.size()) {

					thread t(process_func, lap_data_);
					t.detach();

					lap_data_.clear();
					lap_data_.push_back(*tdecoder);
				}
				else {
					lap_data_.push_back(*tdecoder);
				}
			}
		}
		else {
			if (global_live_lap) {
				global_live_lap->live(tdecoder);
			}
			if (global_process_lap) {
				lap_data_.push_back(*tdecoder);
			}
		}
	}
}

}

