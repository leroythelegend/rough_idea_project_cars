#ifndef PCARS_DECODER_16TIMES_U16_H_
#define PCARS_DECODER_16TIMES_U16_H_

#include "decodercomposite.h"

#include "decoderu16.h"

namespace pcars {

class Decoder_16Times_U16 : public Decoder_Composite {
public:
	Decoder_16Times_U16();
	virtual ~Decoder_16Times_U16() {}

	Vector_UInt times16_u16() const;

private:
	Decoder_U16 first_;
	Decoder_U16 second_;
	Decoder_U16 third_;
	Decoder_U16 forth_;
	Decoder_U16 fith_;
	Decoder_U16 sixth_;
	Decoder_U16 seventh_;
	Decoder_U16 eightth_;
	Decoder_U16 nineth_;
	Decoder_U16 tenth_;
	Decoder_U16 eleventh_;
	Decoder_U16 twelve_;
	Decoder_U16 thirteen_;
	Decoder_U16 forteen_;
	Decoder_U16 fithteen_;
	Decoder_U16 sixteen_;
};

}

#endif

