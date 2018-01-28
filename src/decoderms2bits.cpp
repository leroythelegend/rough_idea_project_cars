#include "decoderms2bits.h"

#include "exception.h"

namespace pcars {

Decoder_MS2bits::Decoder_MS2bits()
	: num_{0} {
}

void Decoder_MS2bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 4) & 3;
}

unsigned int Decoder_MS2bits::ms2bits() const {
	return num_;
}

}

