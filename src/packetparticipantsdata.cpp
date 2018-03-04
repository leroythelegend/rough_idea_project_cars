#include "packetparticipantsdata.h"

namespace pcars {

Packet_Participants_Data::Packet_Participants_Data() {
	add(&packet_base_);		
	add(&participants_changed_timestamp_);
	add(&name_);
	add(&nationality_);
	add(&index_);
}

Packet_Base Packet_Participants_Data::packet_base() const {
	return packet_base_;
}

unsigned int Packet_Participants_Data::participants_changed_timestamp() const {
	return participants_changed_timestamp_.u32();
}

Vector_String Packet_Participants_Data::name() const {
	return name_.times16_64Char();
}

Vector_UInt Packet_Participants_Data::nationality() const {
	return nationality_.times16_u32();
}

Vector_UInt Packet_Participants_Data::index() const {
	return index_.times16_u16();
}

}


