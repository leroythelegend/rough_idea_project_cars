#include "decoderneg1ftopos1f.h"

#include "exception.h"

namespace pcars {

Decoder_Neg1F_To_Pos1F::Decoder_Neg1F_To_Pos1F()
	: num_(0) {
}

Decoder_Neg1F_To_Pos1F::~Decoder_Neg1F_To_Pos1F() {
}

void Decoder_Neg1F_To_Pos1F::decode(const PCars_Data & data, Position & position) {
	// find out if it is signed
	int value = 0;
	if (data.at(position) >> 7) { // signed
		value = value - (data.at(position) & 127);
	}
	else {
		value = (data.at(position) & 127);
	}

	num_ = (value / 127);

	++position;
}

float Decoder_Neg1F_To_Pos1F::neg1f_pos1f() const {
	return num_;
}


}

