#include "decoderboolu8.h"

namespace pcars {

Decoder_Bool_U8::Decoder_Bool_U8() {
	add(&bool_);
	add(&num_);
}

void Decoder_Bool_U8::decode(const PCars_Data & data, Position & position) {
	Decoder_Composite::decode(data, position);
	++position;
}

bool Decoder_Bool_U8::msb_bool() const {
	return bool_.msb_bool();
}
unsigned int Decoder_Bool_U8::ls7_bits() const {
	return num_.ls7bits();
}

}

