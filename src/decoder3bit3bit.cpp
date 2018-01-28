#include "decoder3bit3bit.h"

namespace pcars {

Decoder_3bit_3bit::Decoder_3bit_3bit() {
	add(&ms3bits_);
	add(&ls3bits_);
}

void Decoder_3bit_3bit::decode(const PCars_Data &data, Position &position) {
	Decoder_Composite::decode(data, position);
	++position;
}

unsigned int Decoder_3bit_3bit::ms3bits() const {
	return ms3bits_.ms3bits();
}

unsigned int Decoder_3bit_3bit::ls3bits() const {
	return ls3bits_.ls3bits();
}

}

