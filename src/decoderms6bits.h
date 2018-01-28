#ifndef PCARS_MS6BITS_H_
#define PCARS_MS6BITS_H_

#include "decoder.h"

namespace pcars {

class Decoder_MS6bits : public Decoder {
public:
	Decoder_MS6bits();
	virtual ~Decoder_MS6bits();

	void decode(const PCars_Data &, Position &) override;

	unsigned int ms6bits() const;

private:
	int num_;
};

} /* namespace pcars */

#endif /* PCARS_MS6BITS_H_ */
