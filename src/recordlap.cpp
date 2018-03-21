#include "recordlap.h"

#include <iostream>
#include <thread>
#include <mutex>

#include "process.h"
#include "capturetelemetry.h"

#include "packet.h"

using namespace std;

namespace pcars {

std::mutex global_mutex_;

class Thread_Args 
{
public:
	Thread_Args(Process * process, Process::Lap_Data & data)
		: process_(process),
		  data_(data) {}
	
	Process * process_;
	Process::Lap_Data data_;
};


void process_func(const Thread_Args & args) {
	unique_lock<mutex> lck(global_mutex_);
	args.process_->process(args.data_);
};

Record_Post_Lap::Record_Post_Lap(Process * process)
	: process_{process},
	  lap_number_{-1},
	  restart_{false}
{
}


void Record_Post_Lap::record(std::shared_ptr<Data> data)
{
	if (static_cast<Pit_Mode>(data->game_states()->pit_mode()) == Pit_Mode::PIT_MODE_IN_GARAGE) {
		lap_data_.clear();
	}
	if (-1 != data->times()->current_time()) {
		if (lap_number_ != static_cast<int>(data->participants_info()->current_lap(0))) {
			lap_number_ = data->participants_info()->current_lap(0);
			if (lap_data_.size()) {

				thread t(process_func, Thread_Args(process_, lap_data_));
				t.detach();

				lap_data_.clear();
				lap_data_.push_back(data);
			}
			else {
				lap_data_.push_back(data);
			}
		}
		else {
			lap_data_.push_back(data);
		}
	}
	else {
		lap_number_ = -1;
	}
}

Record_Live_Data::Record_Live_Data(Live * live) 
	: live_{live} {}


void Record_Live_Data::record(std::shared_ptr<Data> data)
{
	live_->live(data);
}

}

