#ifndef PCARS_DECODER_4TIMES_S16_H_
#define PCARS_DECODER_4TIMES_S16_H_

#include "decodercomposite.h"

#include "decoders16.h"

namespace pcars {

class Decoder_4Times_S16 : public Decoder_Composite {
public:
	Decoder_4Times_S16();
	virtual ~Decoder_4Times_S16() {}

	Vector_Int times4_s16() const;

private:
	Decoder_S16 first_;
	Decoder_S16 second_;
	Decoder_S16 third_;
	Decoder_S16 forth_;
};

}

#endif

