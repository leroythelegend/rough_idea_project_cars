#ifndef PCARS_DECODER_BOOL_U8_H_
#define PCARS_DECODER_BOOL_U8_H_

#include "decodercomposite.h"

#include "decodermsbbool.h"
#include "decoderls7bits.h"

namespace pcars {

class Decoder_Bool_U8 : public Decoder_Composite {
public:
	Decoder_Bool_U8();
	virtual ~Decoder_Bool_U8() {}

	void decode(const PCars_Data &, Position &) override;

	bool msb_bool() const;
	unsigned int ls7_bits() const;

private:
	Decoder_MSBBool bool_;
	Decoder_LS7bits num_;
};

}

#endif

