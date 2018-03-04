#include "datatimesformat2.h"

namespace pcars {

Data_Times_Format_2::Data_Times_Format_2(std::shared_ptr<Packet> packet)
	: packet_{packet} {}

float Data_Times_Format_2::current_time() const {
	return packet_->timing_data().partcipants().at(0).current_time();
}

float Data_Times_Format_2::current_sector1_time() const {
	return packet_->timing_data().partcipants().at(0).current_sector_time();
}

float Data_Times_Format_2::current_sector2_time() const {
	return packet_->timing_data().partcipants().at(0).current_sector_time();
}

float Data_Times_Format_2::current_sector3_time() const {
	return packet_->timing_data().partcipants().at(0).current_sector_time();
}

float Data_Times_Format_2::fastest_sector1_time() const {
	return packet_->time_stats_data().stats().at(0).fastest_sector1_time();
}

float Data_Times_Format_2::fastest_sector2_time() const {
	return packet_->time_stats_data().stats().at(0).fastest_sector2_time();
}

float Data_Times_Format_2::fastest_sector3_time() const {
	return packet_->time_stats_data().stats().at(0).fastest_sector3_time();
}

}

