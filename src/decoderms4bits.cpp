#include "decoderms4bits.h"

#include "exception.h"

namespace pcars {

Decoder_MS4bits::Decoder_MS4bits()
	: num_(0) {
}

Decoder_MS4bits::~Decoder_MS4bits() {
}

void Decoder_MS4bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 4) & 15;
}

unsigned int Decoder_MS4bits::ms4bits() const {
	return num_;
}

}

