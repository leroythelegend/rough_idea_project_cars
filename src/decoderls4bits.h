#ifndef PCARS_DECODER_LS4BITS_H_
#define PCARS_DECODER_LS4BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_LS4bits : public Decoder {
public:
	Decoder_LS4bits();
	virtual ~Decoder_LS4bits();
	void decode(const PCars_Data &, Position &) override;

	unsigned int ls4bits() const;

private:
	unsigned int num_;
};

}

#endif

