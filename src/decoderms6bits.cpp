#include "decoderms6bits.h"

#include "exception.h"

namespace pcars {

Decoder_MS6bits::Decoder_MS6bits()
	: num_(0) {

}

Decoder_MS6bits::~Decoder_MS6bits() {
}

void Decoder_MS6bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 2);
}

unsigned int Decoder_MS6bits::ms6bits() const {
	return num_;
}

}

