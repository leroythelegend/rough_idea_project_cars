#ifndef PCAR_DECODER_U32_H_
#define PCAR_DECODER_U32_H_

#include "decoder.h"

namespace pcars {

class Decoder_U32 : public Decoder {
public:
	Decoder_U32();
	virtual ~Decoder_U32() {}

	void decode(const PCars_Data &, Position &) override;

	unsigned int u32() const;

private:
	unsigned int num_;
};

}

#endif

