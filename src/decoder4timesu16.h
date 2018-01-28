#ifndef PCARS_DECODER_4TIMES_U16_H_
#define PCARS_DECODER_4TIMES_U16_H_

#include "decodercomposite.h"

#include "decoderu16.h"

namespace pcars {

class Decoder_4Times_U16 : public Decoder_Composite {
public:
	Decoder_4Times_U16();
	virtual ~Decoder_4Times_U16() {}

	Vector_U16 times4_u16() const;

private:
	Decoder_U16 first_;
	Decoder_U16 second_;
	Decoder_U16 third_;
	Decoder_U16 forth_;
};

}

#endif

