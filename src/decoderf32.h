#ifndef PCARS_DECODER_F32_H_
#define PCARS_DECODER_F32_H_

#include "decoder.h"

namespace pcars {

class Decoder_F32: public Decoder {
public:
	Decoder_F32();
	virtual ~Decoder_F32() {}

	void decode(const PCars_Data &, Position &) override;

	float f32() const;

private:
	float num_;
};

} /* namespace pcars */

#endif /* PCARS_DECODER_F32_H_ */
