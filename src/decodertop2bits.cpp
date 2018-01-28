#include "decodertop2bits.h"

namespace pcars {

Decoder_Top_2bits::Decoder_Top_2bits()
	: num_(0) {
}

Decoder_Top_2bits::~Decoder_Top_2bits() {
}

void Decoder_Top_2bits::decode(const PCars_Data & data, Position & position) {
	num_ = ((data.at(position) >> 5) & 3);
}

unsigned int Decoder_Top_2bits::top_2bit() const {
	return num_;
}

}

