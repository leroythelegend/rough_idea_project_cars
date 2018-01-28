#ifndef PCARS_3TIMES_S16_H_
#define PCARS_3TIMES_S16_H_

#include "decodercomposite.h"

#include "decoders16.h"

namespace pcars {

class Decoder_3Times_S16 : public Decoder_Composite {
public:
	Decoder_3Times_S16();
	virtual ~Decoder_3Times_S16() {}

	Vector_S16 times3_s16() const;

private:
	Decoder_S16 first_;
	Decoder_S16 second_;
	Decoder_S16 third_;
};

}

#endif

