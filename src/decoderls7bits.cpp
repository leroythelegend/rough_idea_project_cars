#include "decoderls7bits.h"

namespace pcars {

Decoder_LS7bits::Decoder_LS7bits()
	: num_(0) {

}

Decoder_LS7bits::~Decoder_LS7bits() {
}

void Decoder_LS7bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) & 127);
}

unsigned int Decoder_LS7bits::ls7bits() const {
	return num_;
}

}

