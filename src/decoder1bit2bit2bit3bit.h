#ifndef PCARS_DECODER_1BIT_2BIT_2BIT_3BIT_H_
#define PCARS_DECODER_1BIT_2BIT_2BIT_3BIT_H_

#include "decodercomposite.h"

#include "decoderls3bits.h"
#include "decoderbottom2bits.h"
#include "decodertop2bits.h"
#include "decodermsbbool.h"

namespace pcars {

class Decoder_1bit_2bit_2bit_3bit: public Decoder_Composite {
public:
	Decoder_1bit_2bit_2bit_3bit();
	virtual ~Decoder_1bit_2bit_2bit_3bit();

	void decode(const PCars_Data &, Position &) override;

	unsigned int lsb_3bit() const;
	unsigned int bottom_2bit() const;
	unsigned int top_2bit() const;
	bool msb_1bit() const;

private:
	Decoder_LS3bits lsb3bit_;
	Decoder_Bottom_2bits b2bit_;
	Decoder_Top_2bits t2bit_;
	Decoder_MSBBool msb1bit_;
};

}

#endif

