#include "decoder2bit3bit.h"

namespace pcars {

Decoder_2bit_3bit::Decoder_2bit_3bit() {
	add(&ms2bits_);
	add(&ls3bits_);
}

void Decoder_2bit_3bit::decode(const PCars_Data & data, Position & position) {
	Decoder_Composite::decode(data, position);
	++position;
}

unsigned int Decoder_2bit_3bit::ms2bits() const {
	return ms2bits_.ms2bits();
}

unsigned int Decoder_2bit_3bit::ls3bits() const {
	return ls3bits_.ls3bits();
}

}
