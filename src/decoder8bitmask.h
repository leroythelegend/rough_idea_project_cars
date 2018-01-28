#ifndef PCARS_DECODER_8BIT_MASK_H_
#define PCARS_DECODER_8BIT_MASK_H_

#include "decoder.h"

namespace pcars {

class Decoder_8bit_Mask : public Decoder {
public:
	Decoder_8bit_Mask();
	virtual ~Decoder_8bit_Mask() {}

	void decode(const PCars_Data &, Position &) override;

	Vector_Bool mask_8bit() const;

private:
	Vector_Bool booldata_;
};

}

#endif

