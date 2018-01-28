#include "decodergeneric.h"

namespace pcars {

Decoder_Generic::Decoder_Generic() {
	add(&buildversion_);
	add(&sequencenum_packettype_);
}

Decoder_Generic::~Decoder_Generic() {
}


uint16_t Decoder_Generic::build_version() const {
	return buildversion_.u16();
}

unsigned int Decoder_Generic::sequence_number() const {
	return sequencenum_packettype_.ms6bits();
}

Packet_Type Decoder_Generic::packet_type() const{
	return static_cast<Packet_Type>(sequencenum_packettype_.ls2bits());
}

}

