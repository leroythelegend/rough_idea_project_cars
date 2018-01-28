#include "decoder64char.h"

#include "exception.h"

namespace pcars {

Decoder_64Char::Decoder_64Char() {
}

void Decoder_64Char::decode(const PCars_Data & data, Position & position) {

	char64_.assign(reinterpret_cast<char *>(data.at(position)), 64);

	position += 64; 
}

std::string Decoder_64Char::char64() const {
	return char64_;
}

}

