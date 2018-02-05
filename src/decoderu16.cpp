#include "decoderu16.h"

#include "exception.h"

namespace pcars {

Decoder_U16::Decoder_U16()
	: num_(0) {
}

Decoder_U16::~Decoder_U16() {
}

void Decoder_U16::decode(const PCars_Data & data, Position & position) {

	num_ = ((data.at(position + 1) << 8) | (data.at(position)));

	position += 2;
}

unsigned int Decoder_U16::u16() const {
	return num_;
}

}

