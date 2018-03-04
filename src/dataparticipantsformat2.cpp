#include "dataparticipantsformat2.h"

namespace pcars {

Data_Participants_Format_2::Data_Participants_Format_2(std::shared_ptr<Packet> packet)
	: packet_{packet} {}

std::string Data_Participants_Format_2::name(Participant participant) const {
	return packet_->participants_data().name().at(participant);
}

unsigned int Data_Participants_Format_2::nationality(Participant participant) const {
	return packet_->participants_data().nationality().at(participant);
}

unsigned int Data_Participants_Format_2::index(Participant participant) const {
	return packet_->participants_data().index().at(participant);
}

}

