#include "decoderls4bits.h"

#include "exception.h"

namespace pcars {

Decoder_LS4bits::Decoder_LS4bits()
	: num_(0) {
}

Decoder_LS4bits::~Decoder_LS4bits() {
}

void Decoder_LS4bits::decode(const PCars_Data & data, Position & position) {
	num_ = data.at(position) & 15;
}

unsigned int Decoder_LS4bits::ls4bits() const {
	return num_;
}

}

