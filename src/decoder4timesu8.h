#ifndef PCARS_DECODER_4TIMES_U8_H_
#define PCARS_DECODER_4TIMES_U8_H_

#include "decodercomposite.h"

#include "decoderu8.h"

namespace pcars {

class Decoder_4Times_U8 : public Decoder_Composite {
public:
	Decoder_4Times_U8();
	virtual ~Decoder_4Times_U8() {}

	Vector_U8 times4_u8() const;

private:
	Decoder_U8 first_;
	Decoder_U8 second_;
	Decoder_U8 third_;
	Decoder_U8 forth_;
};

}

#endif

