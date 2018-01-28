#ifndef PCARS_NEG1F_TO_POS1F_H_
#define PCARS_NEG1F_TO_POS1F_H_

#include "decoder.h"

namespace pcars {

class Decoder_Neg1F_To_Pos1F : public Decoder {
public:
	Decoder_Neg1F_To_Pos1F();
	virtual ~Decoder_Neg1F_To_Pos1F();

	void decode(const PCars_Data &, Position &) override;

	float neg1f_pos1f() const;

private:

	float num_;
};

}

#endif

