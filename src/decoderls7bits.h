#ifndef PCARS_DECODER_LS7BITS_H_
#define PCARS_DECODER_LS7BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_LS7bits : public Decoder {
public:
	Decoder_LS7bits();
	virtual ~Decoder_LS7bits();

	void decode(const PCars_Data &, Position &) override;

	unsigned int ls7bits() const;

private:
	unsigned int num_;
};

}

#endif

