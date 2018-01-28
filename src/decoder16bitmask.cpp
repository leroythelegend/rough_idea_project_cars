#include "decoder16bitmask.h"

#include <bitset>

#include "exception.h"

using std::bitset;

namespace pcars {

Decoder_16bit_Mask::Decoder_16bit_Mask()
	: bool_{false}
{
}

void Decoder_16bit_Mask::decode(const PCars_Data &data, Position &position) {

	bitset<8> first(data.at(position));
	bitset<8> second(data.at(++position));

	for (unsigned int i = 0; i < 8; ++i) {
		bool_.push_back(second[i]);
	}

	for (unsigned int i = 0; i < 8; ++i) {
		bool_.push_back(first[i]);
	}

	++position;
}

Vector_Bool Decoder_16bit_Mask::mask_16bit() const {
	return bool_;
}

}

