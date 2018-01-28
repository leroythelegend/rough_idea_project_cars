#ifndef PCARS_DECODER_3BIT_H_
#define PCARS_DECODER_3BIT_H_

#include "decodercomposite.h"

#include "decoderls3bits.h"

namespace pcars {

class Decoder_3bit: public Decoder_Composite {
public:
	Decoder_3bit();
	virtual ~Decoder_3bit() {}

	void decode(const PCars_Data &, Position &) override;

	unsigned int ls3bits() const;

private:
	Decoder_LS3bits ls3bits_;
};

}

#endif

