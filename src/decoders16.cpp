#include "decoders16.h"

#include "exception.h"

namespace pcars {

Decoder_S16::Decoder_S16()
	: num_(0) {
}

Decoder_S16::~Decoder_S16() {
}

void Decoder_S16::decode(const PCars_Data & data, Position & position) {

	num_ = ((data.at(position + 1) << 8) | data.at(position));

	position += 2;
}

int16_t Decoder_S16::s16() const {
	return num_;
}

}

