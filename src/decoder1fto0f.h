#ifndef PCARS_DECODER_ONEFTO0F_H_
#define PCARS_DECODER_ONEFTO0F_H_

#include "decoder.h"

namespace pcars {

class Decoder_1Fto0F : public Decoder {
public:
	Decoder_1Fto0F();
	virtual ~Decoder_1Fto0F() {}

	void decode(const PCars_Data &, Position &) override;

	float f1tof0() const;

private:
	float num_;
};

}

#endif

