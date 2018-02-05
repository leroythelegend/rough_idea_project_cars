#include "packetbase.h"

namespace pcars {

Packet_Base::Packet_Base() {
	add(&packet_number_);
	add(&category_packet_number_);
	add(&partial_packet_index_);
	add(&partial_packet_number_);
	add(&packet_type_);
	add(&packet_version_);
}

unsigned int Packet_Base::packet_number() const {
	return packet_number_.u32(); 
}

unsigned int Packet_Base::category_packet_number() const {
	return category_packet_number_.u32(); 
}

unsigned int Packet_Base::partial_packet_index() const {
	return partial_packet_index_.u8();
}

unsigned int Packet_Base::partial_packet_number() const {
	return partial_packet_number_.u8();
}

unsigned int Packet_Base::packet_type() const {
	return packet_type_.u8();
}

unsigned int Packet_Base::packet_version() const {
	return packet_version_.u8();
}

}


