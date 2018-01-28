#include "decoderls3bits.h"

#include "exception.h"

namespace pcars {

Decoder_LS3bits::Decoder_LS3bits()
	: num_(0) {

}

Decoder_LS3bits::~Decoder_LS3bits() {
}

void Decoder_LS3bits::decode(const PCars_Data & data, Position & position) {
	num_ = data.at(position) & 7;
}

unsigned int Decoder_LS3bits::ls3bits() const {
	return num_;
}

}

