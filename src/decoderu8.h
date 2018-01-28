#ifndef PCARS_DECODER_U8_H_
#define PCARS_DECODER_U8_H_

#include <cstdint>

#include "decoder.h"

namespace pcars {

class Decoder_U8 : public Decoder {
public:
	Decoder_U8();
	virtual ~Decoder_U8();

	void decode(const PCars_Data &, Position &) override;

	uint8_t u8() const;

private:
	uint8_t num_;
};

}

#endif

