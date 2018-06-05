#include "packettimingdata.h"

namespace pcars {

Packet_Timing_Data::Packet_Timing_Data() {

	add(&packet_base_);
	add(&num_participants_);
	add(&participants_changed_timestamp_);
	add(&event_time_remaining_);
	add(&split_time_ahead_);
	add(&split_time_behind_);
	add(&split_time_);
	add(&partcipants_);
	add(&local_participant_index_);
	add(&tick_count_);
}

Packet_Base Packet_Timing_Data::packet_base() const {
	return packet_base_;
}

int Packet_Timing_Data::num_participants() const {
	return num_participants_.s8(); 
}

unsigned int Packet_Timing_Data::participants_changed_timestamp() const {
	return participants_changed_timestamp_.u32(); 
}

float Packet_Timing_Data::event_time_remaining() const {
	return event_time_remaining_.f32(); 
}

float Packet_Timing_Data::split_time_ahead() const {
	return split_time_ahead_.f32(); 
}

float Packet_Timing_Data::split_time_behind() const {
	return split_time_behind_.f32(); 
}

float Packet_Timing_Data::split_time() const {
	return split_time_.f32(); 
}

Packet_32_Participant_Info::Vector_Participant_Info Packet_Timing_Data::partcipants() const {
	return partcipants_.participant_info() ; 
}

unsigned int Packet_Timing_Data::local_participant_index() const {
	return 0; 
}

unsigned int Packet_Timing_Data::tick_count() const {
	return tick_count_.u32(); 
}


}

