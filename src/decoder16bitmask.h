#ifndef PCARS_DECODER_16BIT_MASK_H_
#define PCARS_DECODER_16BIT_MASK_H_

#include "decoder.h"

namespace pcars {

class Decoder_16bit_Mask: public Decoder {
public:
	Decoder_16bit_Mask();
	virtual ~Decoder_16bit_Mask() {}

	void decode(const PCars_Data &, Position &) override;

	Vector_Bool mask_16bit() const;

private:

	Vector_Bool bool_;
};

}

#endif
