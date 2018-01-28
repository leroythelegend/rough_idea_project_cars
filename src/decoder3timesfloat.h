#ifndef PCARS_DECODER_3TIMES_FLOAT_H_
#define PCARS_DECODER_3TIMES_FLOAT_H_

#include "decodercomposite.h"

#include "decoderf32.h"

namespace pcars {

class Decoder_3Times_Float : public Decoder_Composite {
public:
	Decoder_3Times_Float();
	virtual ~Decoder_3Times_Float() {}

	Vector_Float times3_float() const;

private:
	Decoder_F32 first_;
	Decoder_F32 second_;
	Decoder_F32 third_;
};

}

#endif

