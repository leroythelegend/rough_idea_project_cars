#include "decoder40char.h"

#include "exception.h"

namespace pcars {

Decoder_40Char::Decoder_40Char() {
}

void Decoder_40Char::decode(const PCars_Data & data, Position & position) {

	char40_.assign(data.begin() + position, data.begin() + (position + 40));

	position += 40; 
}

std::string Decoder_40Char::char40() const {
	return char40_;
}

}

