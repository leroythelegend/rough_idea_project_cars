#ifndef PCARS_DECODER_40CHAR_H_
#define PCARS_DECODER_40CHAR_H_

#include "decoder.h"

#include <string>

namespace pcars {

class Decoder_40Char : public Decoder {
public:
	Decoder_40Char();
	virtual ~Decoder_40Char() {}

	void decode(const PCars_Data &, Position &) override;

	std::string char40() const;

private:
	std::string char40_;
};

}

#endif

