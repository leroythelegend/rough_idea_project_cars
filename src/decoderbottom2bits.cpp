#include "decoderbottom2bits.h"

namespace pcars {

Decoder_Bottom_2bits::Decoder_Bottom_2bits()
	: num_{0} {

}

void Decoder_Bottom_2bits::decode(const PCars_Data & data, Position & position) {
	num_ = ((data.at(position) >> 3) & 3);
}

unsigned int Decoder_Bottom_2bits::bottom_2bit() const {
	return num_;
}

}

