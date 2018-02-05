#ifndef PCARS_DECODER_S16_H_
#define PCARS_DECODER_S16_H_

#include "decoder.h"

#include <cstdint>

namespace pcars {

class Decoder_S16: public Decoder {
public:
	Decoder_S16();
	virtual ~Decoder_S16();

	void decode(const PCars_Data &, Position &) override;

	int s16() const;

private:
	int16_t num_;
};

}

#endif
