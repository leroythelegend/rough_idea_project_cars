#include "packettimestatsdata.h"

namespace pcars {

	Packet_Time_Stats_Data::Packet_Time_Stats_Data() {
	add(&packet_base_);		
	add(&participants_changed_timestamp_);
	add(&stats_);
}

Packet_Base Packet_Time_Stats_Data::packet_base() const	 {
	return packet_base_;
}

unsigned int Packet_Time_Stats_Data::participants_changed_timestamp() const {
	return participants_changed_timestamp_.u32();
}

Packet_32_Participants_Stats_Info::Vector_Participants_Stats_Info Packet_Time_Stats_Data::stats() const {
	return stats_.participants_stats_info();
}



}


