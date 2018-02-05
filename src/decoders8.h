#ifndef PCARS_DECODER_S8_H_
#define PCARS_DECODER_S8_H_

#include "decoder.h"

#include <cstdint>

namespace pcars {

class Decoder_S8 : public Decoder {
public:
	Decoder_S8();
	virtual ~Decoder_S8();

	void decode(const PCars_Data &, Position &) override;

	int s8() const;

private:
	int8_t num_;
};

}

#endif
