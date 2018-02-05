#ifndef PCARS_DECODER_16TIMES_64CHAR_H_
#define PCARS_DECODER_16TIMES_64CHAR_H_

#include "decodercomposite.h"

#include "decoder64char.h"

namespace pcars {

class Decoder_16Times_64Char : public Decoder_Composite {
public:
	Decoder_16Times_64Char();
	virtual ~Decoder_16Times_64Char() {}

	Vector_String times16_64Char() const;

private:
	Decoder_64Char first_;
	Decoder_64Char second_;
	Decoder_64Char third_;
	Decoder_64Char forth_;
	Decoder_64Char fith_;
	Decoder_64Char sixth_;
	Decoder_64Char seventh_;
	Decoder_64Char eightth_;
	Decoder_64Char nineth_;
	Decoder_64Char tenth_;
	Decoder_64Char eleventh_;
	Decoder_64Char twelve_;
	Decoder_64Char thirteen_;
	Decoder_64Char forteen_;
	Decoder_64Char fithteen_;
	Decoder_64Char sixteen_;
};

}

#endif

