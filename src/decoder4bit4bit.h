#ifndef PCARS_DECODER_4BIT_4BIT_H_
#define PCARS_DECODER_4BIT_4BIT_H_

#include "decodercomposite.h"

#include "decoderms4bits.h"
#include "decoderls4bits.h"

namespace pcars {

class Decoder_4bit_4bit : public Decoder_Composite {
public:
	Decoder_4bit_4bit();
	virtual ~Decoder_4bit_4bit() {}

	void decode(const PCars_Data &, Position &) override;

	unsigned int ms4bits() const;
	unsigned int ls4bits() const;

private:
	Decoder_MS4bits ms4bits_;
	Decoder_LS4bits ls4bits_;
};

}

#endif

