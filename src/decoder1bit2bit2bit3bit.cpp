#include "decoder1bit2bit2bit3bit.h"

namespace pcars {

Decoder_1bit_2bit_2bit_3bit::Decoder_1bit_2bit_2bit_3bit() {
	add(&lsb3bit_);
	add(&b2bit_);
	add(&t2bit_);
	add(&msb1bit_);
}

Decoder_1bit_2bit_2bit_3bit::~Decoder_1bit_2bit_2bit_3bit() {
}

void Decoder_1bit_2bit_2bit_3bit::decode(const PCars_Data &data, unsigned int &position) {
	Decoder_Composite::decode(data, position);
	++position;
}

unsigned int Decoder_1bit_2bit_2bit_3bit::lsb_3bit() const {
	return lsb3bit_.ls3bits();
}

unsigned int Decoder_1bit_2bit_2bit_3bit::bottom_2bit() const {
	return b2bit_.bottom_2bit();
}

unsigned int Decoder_1bit_2bit_2bit_3bit::top_2bit() const {
	return t2bit_.top_2bit();
}

bool Decoder_1bit_2bit_2bit_3bit::msb_1bit() const {
	return msb1bit_.msb_bool();
}


}

