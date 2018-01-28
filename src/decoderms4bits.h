#ifndef PCARS_DECODER_MS4BITS_H_
#define PCARS_DECODER_MS4BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_MS4bits : public Decoder {
public:
	Decoder_MS4bits();
	virtual ~Decoder_MS4bits();

	void decode(const PCars_Data &, Position &) override;

	unsigned int ms4bits() const;

private:
	unsigned int num_;

};

}

#endif

