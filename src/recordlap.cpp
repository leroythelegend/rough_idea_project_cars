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

class Thread_Args_V2 
{
public:
	Thread_Args_V2(Process * process, Process::Lap_Data_V2 data)
		: process_(process),
		  data_(data) {}
	
	Process * process_;
	Process::Lap_Data_V2 data_;
};

void process_func(const Thread_Args & args) {
	unique_lock<mutex> lck(global_mutex_);
	args.process_->process(args.data_);
};

void process_func_v2(const Thread_Args_V2 args) {
	unique_lock<mutex> lck(global_mutex_);
	args.process_->process(args.data_);
};


Record_Post_Lap::Record_Post_Lap(Process * process)
	: process_{process},
	  lap_number_{-1}
{
}

void Record_Post_Lap::record(Decoder * )
{
//	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);
//	if (tdecoder) {
//		if (lap_number_ != static_cast<int>(tdecoder->participant_info().at(0).current_lap())) {
//			lap_number_ = tdecoder->participant_info().at(0).current_lap();
//			if (lap_data_.size()) {
//
//				thread t(process_func, Thread_Args(process_, lap_data_));
//				t.detach();
//
//				lap_data_.clear();
//				lap_data_.push_back(*tdecoder);
//			}
//			else {
//					lap_data_.push_back(*tdecoder);
//			}
//		}
//		else {
//			lap_data_.push_back(*tdecoder);
//		}
//	}
}

void Record_Post_Lap::record(std::shared_ptr<Data> data)
{
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


Record_Post_Lap_V2::Record_Post_Lap_V2(Process * process)
	: process_{process},
	  lap_number_{-1}
{
}

void Record_Post_Lap_V2::record(Decoder * decoder)
{
	Packet * packet = dynamic_cast<Packet *>(decoder);
	if (packet) {
		if (lap_number_ != static_cast<int>(packet->timing_data().partcipants().at(0).current_lap())) {
			lap_number_ = packet->timing_data().partcipants().at(0).current_lap();
			if (lap_data_.size()) {

				thread t(process_func_v2, Thread_Args_V2(process_, lap_data_));
				t.detach();

				lap_data_.clear();
				lap_data_.push_back(*packet);
			}
			else {
					lap_data_.push_back(*packet);
			}
		}
		else {
			lap_data_.push_back(*packet);
		}
	}
}


Record_Live_Data::Record_Live_Data(Live * live) 
	: live_{live} {}

void Record_Live_Data::record(Decoder * decoder)
{
	live_->live(decoder);
}

void Record_Live_Data::record(std::shared_ptr<Data> data)
{
	live_->live(data);
}



}

