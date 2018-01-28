#ifndef PCARS_DECODER_LS3BITS_H_
#define PCARS_DECODER_LS3BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_LS3bits: public Decoder {
public:
	Decoder_LS3bits();
	virtual ~Decoder_LS3bits();

	void decode(const PCars_Data &, Position &) override;

	unsigned int ls3bits() const;

private:
	unsigned int num_;
};

}

#endif

