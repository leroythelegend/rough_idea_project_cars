#include "decoderu8.h"

#include "exception.h"

namespace pcars {

Decoder_U8::Decoder_U8()
	: num_(0) {
}

Decoder_U8::~Decoder_U8() {
}

void Decoder_U8::decode(const PCars_Data & data, Position & position) {

	num_ = data.at(position);
	++position;
}

uint8_t Decoder_U8::u8() const {
	return num_;
}

}

