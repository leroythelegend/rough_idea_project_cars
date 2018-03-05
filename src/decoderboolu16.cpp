#include "decoderboolu16.h"

namespace pcars {

Decoder_Bool_U16::Decoder_Bool_U16() {
	add(&bool_);
	add(&num_);
}

void Decoder_Bool_U16::decode(const PCars_Data & data, Position & position) {
	Decoder_Composite::decode(data, position);
}

bool Decoder_Bool_U16::msb_bool() const {
	return bool_.msb_bool();
}
unsigned int Decoder_Bool_U16::u15() const {
	return num_.u15();
}

}
