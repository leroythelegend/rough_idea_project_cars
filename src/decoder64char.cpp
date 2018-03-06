#include "decoder64char.h"

#include "exception.h"

namespace pcars {

Decoder_64Char::Decoder_64Char() {
}

void Decoder_64Char::decode(const PCars_Data & data, Position & position) {

	char64_.assign(data.begin() + position, data.begin() + (position + 64));

	position += 64; 
}

std::string Decoder_64Char::char64() const {
	std::string str = char64_;
	return str.substr(0, str.find('\0'));
}

}

