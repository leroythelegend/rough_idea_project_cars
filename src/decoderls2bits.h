#ifndef PCARS_DECODER_LS2BITS_H_
#define PCARS_DECODER_LS2BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_LS2bits : public Decoder {
public:
	Decoder_LS2bits();
	virtual ~Decoder_LS2bits();

	void decode(const PCars_Data &, Position &) override;

	unsigned int ls2bits() const;

private:
	int num_;
};

}

#endif

