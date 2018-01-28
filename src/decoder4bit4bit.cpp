#include "decoder4bit4bit.h"

namespace pcars {

Decoder_4bit_4bit::Decoder_4bit_4bit() {
	add(&ms4bits_);
	add(&ls4bits_);
}

void Decoder_4bit_4bit::decode(const PCars_Data & data, Position & position) {
	Decoder_Composite::decode(data, position);
	++position;
}

unsigned int Decoder_4bit_4bit::ms4bits() const {
	return ms4bits_.ms4bits();
}

unsigned int Decoder_4bit_4bit::ls4bits() const {
	return ls4bits_.ls4bits();
}

}
