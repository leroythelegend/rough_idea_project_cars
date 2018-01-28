#include "decoderms3bits.h"

#include "exception.h"

namespace pcars {

Decoder_MS3bits::Decoder_MS3bits()
	: num_(0) {
}

Decoder_MS3bits::~Decoder_MS3bits() {
}

void Decoder_MS3bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 4) & 7;
}

unsigned int Decoder_MS3bits::ms3bits() const {
	return num_;
}

}

