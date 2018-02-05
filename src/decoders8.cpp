#include "decoders8.h"

#include "exception.h"

namespace pcars {

Decoder_S8::Decoder_S8()
	: num_(0) {
}

Decoder_S8::~Decoder_S8() {
}

void Decoder_S8::decode(const PCars_Data & data, Position & position) {

	num_ = data.at(position);

	++position;
}

int Decoder_S8::s8() const {
	return num_;
}

}

