#ifndef PCARS_DECODER_MSBBOOL_H_
#define PCARS_DECODER_MSBBOOL_H_

#include "decoder.h"

namespace pcars {

class Decoder_MSBBool : public Decoder {
public:
	Decoder_MSBBool();
	virtual ~Decoder_MSBBool();

	void decode(const PCars_Data &, Position &) override;

	bool msb_bool() const;

private:
	bool num_;
};

}

#endif

