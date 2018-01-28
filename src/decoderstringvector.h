#ifndef PCARS_DECODER_STRING_VECTOR_H_
#define PCARS_DECODER_STRING_VECTOR_H_

#include "decoder.h"

#include <string>
#include <vector>

namespace pcars {

class Decoder_String_Vector : public Decoder {
public:
	using Num_Participants = int8_t;

	Decoder_String_Vector(Num_Participants);
	virtual ~Decoder_String_Vector();

	void decode(const PCars_Data &, Position &) override;

	Vector_String string_vector() const;

private:
	Num_Participants numparticipants_;
	Vector_String stringvector_;
};

}

#endif
