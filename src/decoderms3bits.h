#ifndef PCARS_DECODER_MS3BITS_H_
#define PCARS_DECODER_MS3BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_MS3bits: public Decoder {
public:
	Decoder_MS3bits();
	virtual ~Decoder_MS3bits();

	void decode(const PCars_Data &, Position &) override;

	unsigned int ms3bits() const;

private:
	unsigned int num_;
};

}

#endif

