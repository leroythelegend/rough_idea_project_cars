#include "packet32participantsstatsinfo.h"

namespace pcars {

Packet_32_Participants_Stats_Info::Packet_32_Participants_Stats_Info() 
	: particpants_stats_info_(32) {
	for (unsigned int i = 0; i < particpants_stats_info_.size(); ++i) {
		add(&particpants_stats_info_.at(i));
	}
}

Packet_32_Participants_Stats_Info::Vector_Participants_Stats_Info Packet_32_Participants_Stats_Info::participants_stats_info() const {
	return particpants_stats_info_;
}

}
