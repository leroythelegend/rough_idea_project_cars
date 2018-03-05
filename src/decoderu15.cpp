#include "decoderu15.h"

#include "exception.h"

namespace pcars {

Decoder_U15::Decoder_U15()
	: num_(0) {
}

Decoder_U15::~Decoder_U15() {
}

void Decoder_U15::decode(const PCars_Data & data, Position & position) {

	num_ = ((data.at(position + 1) << 8) | (data.at(position) & 127));

	position += 2;
}

unsigned int Decoder_U15::u15() const {
	return num_;
}

}

