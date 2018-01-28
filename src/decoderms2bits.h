#ifndef PCARS_DECODER_MS2BITS_H_
#define PCARS_DECODER_MS2BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_MS2bits: public Decoder {
public:
	Decoder_MS2bits();
	virtual ~Decoder_MS2bits() {}

	void decode(const PCars_Data &, Position &) override;

	unsigned int ms2bits() const;

private:
	int num_;
};

} /* namespace pcars */

#endif /* PCARS_DECODER_MS2BITS_H_ */
