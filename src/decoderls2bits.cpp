#include "decoderls2bits.h"

#include "exception.h"

namespace pcars {

Decoder_LS2bits::Decoder_LS2bits()
	: num_(0) {
}

Decoder_LS2bits::~Decoder_LS2bits() {
}


void Decoder_LS2bits::decode(const PCars_Data & data, Position & position) {
	num_ = data.at(position) & 3;
}

unsigned int Decoder_LS2bits::ls2bits() const {
	return num_;
}

}

