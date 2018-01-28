#ifndef PCARS_DECODER_2TIMESU8_H_
#define PCARS_DECODER_2TIMESU8_H_

#include "decodercomposite.h"

#include "decoderu8.h"

namespace pcars {

class Decoder_2Times_U8: public Decoder_Composite {
public:
	Decoder_2Times_U8();
	virtual ~Decoder_2Times_U8();

	Vector_Float times2_U8() const;

private:
	Decoder_U8 first_;
	Decoder_U8 second_;
};

}

#endif

