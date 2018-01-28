#ifndef PCARS_DECODER_COMPOSITE_H_
#define PCARS_DECODER_COMPOSITE_H_

#include "decoder.h"

namespace pcars {

class Decoder_Composite : public Decoder {
public:
	using Vector_Decoder = std::vector<Decoder *>;

	virtual ~Decoder_Composite() {}

	virtual void decode(const PCars_Data &, Position &);

	void add(Decoder *);

private:
	Vector_Decoder decoders_;
	Vector_Decoder::iterator iter_;
};

}

#endif

