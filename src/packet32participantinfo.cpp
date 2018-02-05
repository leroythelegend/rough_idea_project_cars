#include "packet32participantinfo.h"

namespace pcars {

Packet_32_Participant_Info::Packet_32_Participant_Info() 
	: particpantsinfo_(32) {
	for (unsigned int i = 0; i < particpantsinfo_.size(); ++i) {
		add(&particpantsinfo_.at(i));
	}
}

Packet_32_Participant_Info::Vector_Participant_Info Packet_32_Participant_Info::participant_info() const {
	return particpantsinfo_;
}

}
