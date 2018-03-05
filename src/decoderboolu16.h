#ifndef PCARS_DECODER_BOOL_U16_H_
#define PCARS_DECODER_BOOL_U16_H_

#include "decodercomposite.h"

#include "decodermsbbool.h"
#include "decoderu15.h"

namespace pcars {

class Decoder_Bool_U16 : public Decoder_Composite {
public:
	Decoder_Bool_U16();
	virtual ~Decoder_Bool_U16() {}

	void decode(const PCars_Data &, Position &) override;

	bool msb_bool() const;
	unsigned int u15() const;

private:
	Decoder_MSBBool bool_;
	Decoder_U15 num_;
};

}

#endif

