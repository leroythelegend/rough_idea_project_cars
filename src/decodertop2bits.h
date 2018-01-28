#ifndef PCARS_DECODER_TOP_2BITS_H_
#define PCARS_DECODER_TOP_2BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_Top_2bits : public Decoder {
public:
	Decoder_Top_2bits();
	virtual ~Decoder_Top_2bits();

	void decode(const PCars_Data &, Position &) override;

	unsigned int top_2bit() const;

private:
	unsigned int num_;
};

}

#endif

