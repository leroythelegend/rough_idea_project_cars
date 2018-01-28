#ifndef PCARS_DECODER_4TIMESFLOAT_H_
#define PCARS_DECODER_4TIMESFLOAT_H_

#include "decodercomposite.h"

#include "decoderf32.h"

namespace pcars {

class Decoder_4Times_Float : public Decoder_Composite {
public:
	Decoder_4Times_Float();
	virtual ~Decoder_4Times_Float() {}

	Vector_Float times4_float() const;

private:
	Decoder_F32 first_;
	Decoder_F32 second_;
	Decoder_F32 third_;
	Decoder_F32 forth_;
};

}

#endif

