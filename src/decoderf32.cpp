#include "decoderf32.h"

#include "exception.h"

namespace pcars {

Decoder_F32::Decoder_F32()
	: num_{0} {}

void Decoder_F32::decode(const PCars_Data &data, Position &position) {

	uint32_t val = 	(data.at(position + 3) << 24) |
			(data.at(position + 2) << 16) |
			(data.at(position + 1) << 8)  |
			(data.at(position));

	union {
		uint32_t val;
		float f;
	} u = { val };

	num_ = u.f;

	position += 4;
}

float Decoder_F32::f32() const {
	return num_;
}

}

