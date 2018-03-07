#ifndef PCARS_DECODER_U16_H_
#define PCARS_DECODER_U16_H_

#include <cstdint>

#include "decoder.h"

namespace pcars {

class Decoder_U16 : public Decoder {
public:
	Decoder_U16();
	virtual ~Decoder_U16();

	void decode(const PCars_Data &, Position &) override;

	unsigned int u16() const;

private:
	uint16_t num_;
};

}

#endif

