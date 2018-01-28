#ifndef PCARS_DECODER_64CHAR_H_
#define PCARS_DECODER_64CHAR_H_

#include "decoder.h"

#include <string>

namespace pcars {

class Decoder_64Char : public Decoder {
public:
	Decoder_64Char();
	virtual ~Decoder_64Char() {}

	void decode(const PCars_Data &, Position &) override;

	std::string char64() const;

private:
	std::string char64_;
};

}

#endif

