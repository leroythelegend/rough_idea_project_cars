#ifndef PCARS_DECODER_U15_H_
#define PCARS_DECODER_U15_H_

#include <cstdint>

#include "decoder.h"

namespace pcars {

class Decoder_U15 : public Decoder {
public:
	Decoder_U15();
	virtual ~Decoder_U15();

	void decode(const PCars_Data &, Position &) override;

	unsigned int u15() const;

private:
	uint16_t num_;
};

}

#endif

