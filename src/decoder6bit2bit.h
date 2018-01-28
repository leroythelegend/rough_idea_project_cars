#ifndef PCARS_DECODER_6BIT_2BIT_H_
#define PCARS_DECODER_6BIT_2BIT_H_

#include "decodercomposite.h"

#include "decoderms6bits.h"
#include "decoderls2bits.h"

namespace pcars {

class Decoder_6bit_2bit : public Decoder_Composite {
public:
	Decoder_6bit_2bit();
	virtual ~Decoder_6bit_2bit() {}

	void decode(const PCars_Data &, Position &) override;

	unsigned int ms6bits() const;
	unsigned int ls2bits() const;

private:
	Decoder_MS6bits ms6bits_;
	Decoder_LS2bits ls2bits_;
};

}

#endif

