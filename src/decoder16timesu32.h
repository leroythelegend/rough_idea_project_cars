#ifndef PCARS_DECODER_16TIMES_U32_H_
#define PCARS_DECODER_16TIMES_U32_H_

#include "decodercomposite.h"

#include "decoderu32.h"

namespace pcars {

class Decoder_16Times_U32 : public Decoder_Composite {
public:
	Decoder_16Times_U32();
	virtual ~Decoder_16Times_U32() {}

	Vector_UInt times16_u32() const;

private:
	Decoder_U32 first_;
	Decoder_U32 second_;
	Decoder_U32 third_;
	Decoder_U32 forth_;
	Decoder_U32 fith_;
	Decoder_U32 sixth_;
	Decoder_U32 seventh_;
	Decoder_U32 eightth_;
	Decoder_U32 nineth_;
	Decoder_U32 tenth_;
	Decoder_U32 eleventh_;
	Decoder_U32 twelve_;
	Decoder_U32 thirteen_;
	Decoder_U32 forteen_;
	Decoder_U32 fithteen_;
	Decoder_U32 sixteen_;
};

}

#endif

