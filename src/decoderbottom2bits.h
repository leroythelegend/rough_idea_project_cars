#ifndef PCARS_DECODER_BOTTOM_2BIT_H_
#define PCARS_DECODER_BOTTOM_2BIT_H_

#include "decoder.h"

namespace pcars {

class Decoder_Bottom_2bits : public Decoder {
public:
	Decoder_Bottom_2bits();
	virtual ~Decoder_Bottom_2bits() {}

	void decode(const PCars_Data &, Position &) override;

	unsigned int bottom_2bit() const;

private:
	unsigned int num_;
};

}

#endif

