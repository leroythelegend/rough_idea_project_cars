#include "dataparticipantsstatsformat2.h"

namespace pcars {

Data_Participants_Stats_Format_2::Data_Participants_Stats_Format_2(std::shared_ptr<Packet> packet) 
	: packet_{packet} {}

float Data_Participants_Stats_Format_2::fastest_lap_time(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).fastest_lap_time();
}

float Data_Participants_Stats_Format_2::last_lap_time(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).last_lap_time();
}

float Data_Participants_Stats_Format_2::last_sector_time(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).last_sector_time();
}

float Data_Participants_Stats_Format_2::fastest_sector_1_time(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).fastest_sector1_time();
}

float Data_Participants_Stats_Format_2::fastest_sector_2_time(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).fastest_sector2_time();
}

float Data_Participants_Stats_Format_2::fastest_sector_3_time(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).fastest_sector3_time();
}

unsigned int Data_Participants_Stats_Format_2::participants_online_rank(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).fastest_sector3_time();
}

unsigned int Data_Participants_Stats_Format_2::participants_online_strength(const Participant participant) const {
	return packet_->time_stats_data().stats().at(participant).participant_online_rep();
}


unsigned int Data_Participants_Stats_Format_2::participant_index() const {
	return packet_->timing_data().local_participant_index();
}

Data_Participants_Stats_Format_2::Participants Data_Participants_Stats_Format_2::participants() const {
	return packet_->timing_data().num_participants();
}

}

