#include "decoderu32.h"

#include "exception.h"

namespace pcars {

Decoder_U32::Decoder_U32()
	: num_{0} {}

void Decoder_U32::decode(const PCars_Data & data, Position & position) {

	num_ = 	(data.at(position + 3) << 24) |
			(data.at(position + 2) << 16) |
			(data.at(position + 1) << 8)  |
			 data.at(position);

	position += 4;
}

unsigned int Decoder_U32::u32() const {
	return num_;
}

}

