#include "datasplittimesformat2.h"

namespace pcars {

Data_Split_Times_Format_2::Data_Split_Times_Format_2(const Packet& packet)
	: packet_{packet} {}

unsigned int Data_Split_Times_Format_2::participants_changed_timestamp() const {
	return packet_.timing_data().participants_changed_timestamp();
}

float Data_Split_Times_Format_2::event_time_remaining() const {
	return packet_.timing_data().event_time_remaining();
}

float Data_Split_Times_Format_2::split_time_ahead() const {
	return packet_.timing_data().split_time_ahead();
}

float Data_Split_Times_Format_2::split_time_behind() const {
	return packet_.timing_data().split_time_behind();
}

float Data_Split_Times_Format_2::split_time() const {
	return packet_.timing_data().split_time();
}

unsigned int Data_Split_Times_Format_2::tick_count() const {
	return packet_.timing_data().tick_count();
}






}

