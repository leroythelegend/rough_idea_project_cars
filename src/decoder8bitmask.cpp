#include "decoder8bitmask.h"

#include "exception.h"

#include <bitset>

using std::bitset;

namespace pcars {

Decoder_8bit_Mask::Decoder_8bit_Mask() {
}

void Decoder_8bit_Mask::decode(const PCars_Data & data, Position & position) {

	bitset<8> first(data.at(position));

	for (unsigned int i = 0; i < 8; i++) {
		booldata_.push_back(first[i]);
	}
	++position;
}

Vector_Bool Decoder_8bit_Mask::mask_8bit() const {
	return booldata_;
}

}
