#ifndef PCARS_DECODER_H_
#define PCARS_DECODER_H_

#include "consts.h"

namespace pcars {

class Decoder {
public:
	virtual ~Decoder() {}

	virtual void decode(const PCars_Data &, Position &) = 0;
};

}

#endif

