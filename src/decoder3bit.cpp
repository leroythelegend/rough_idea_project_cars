#include "decoder3bit.h"

namespace pcars {

Decoder_3bit::Decoder_3bit() {
	add(&ls3bits_);

}

void Decoder_3bit::decode(const PCars_Data &data, Position &position) {
	Decoder_Composite::decode(data, position);
	++position;
}

unsigned int Decoder_3bit::ls3bits() const {
	return ls3bits_.ls3bits();
}

}
