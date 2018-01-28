#include "decodermsbbool.h"

namespace pcars {

Decoder_MSBBool::Decoder_MSBBool()
	: num_(true) {
}

Decoder_MSBBool::~Decoder_MSBBool() {
}

void Decoder_MSBBool::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 7);
}

bool Decoder_MSBBool::msb_bool() const {
	return num_;
}

}

