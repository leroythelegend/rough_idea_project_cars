#include "decoder1fto0f.h"

#include "exception.h"

namespace pcars {

Decoder_1Fto0F::Decoder_1Fto0F()
	: num_{0}
{
}

void Decoder_1Fto0F::decode(const PCars_Data & data, unsigned int & position) 
{
	num_ = data.at(position);
	++position;
}

float Decoder_1Fto0F::f1tof0() const {
	return num_;
}

}

