#ifndef PCARS_DECODER_2BIT_3BIT_H_
#define PCARS_DECODER_2BIT_3BIT_H_

#include "decodercomposite.h"

#include "decoderms2bits.h"
#include "decoderls3bits.h"

namespace pcars {

class Decoder_2bit_3bit: public Decoder_Composite {
public:
	Decoder_2bit_3bit();
	virtual ~Decoder_2bit_3bit() {}

	void decode(const PCars_Data&, Position&) override;

	unsigned int ms2bits() const;
	unsigned int ls3bits() const;

private:
	Decoder_MS2bits ms2bits_;
	Decoder_LS3bits ls3bits_;
};

}

#endif

