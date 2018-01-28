#include "decoder6bit2bit.h"

namespace pcars {

Decoder_6bit_2bit::Decoder_6bit_2bit() {
	add(&ms6bits_);
	add(&ls2bits_);
}

void Decoder_6bit_2bit::decode(const PCars_Data & data, Position & position) {
	Decoder_Composite::decode(data, position);
	++position;
}

unsigned int Decoder_6bit_2bit::ms6bits() const {
	return ms6bits_.ms6bits();
}

unsigned int Decoder_6bit_2bit::ls2bits() const {
	return ls2bits_.ls2bits();
}

}
