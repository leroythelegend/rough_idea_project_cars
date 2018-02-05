#ifndef PCARS_DECODER_4TIMES_40CHAR_H_
#define PCARS_DECODER_4TIMES_40CHAR_H_

#include "decodercomposite.h"

#include "decoder40char.h"

namespace pcars {

class Decoder_4Times_40Char : public Decoder_Composite {
public:
	Decoder_4Times_40Char();
	virtual ~Decoder_4Times_40Char() {}

	Vector_String times4_40Char() const;

private:
	Decoder_40Char first_;
	Decoder_40Char second_;
	Decoder_40Char third_;
	Decoder_40Char forth_;
};

}

#endif

