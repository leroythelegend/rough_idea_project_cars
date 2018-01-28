#include "decoderstringvector.h"
#include "decoder64char.h"
#include "exception.h"

namespace pcars {


Decoder_String_Vector::Decoder_String_Vector(int8_t numparticipants) 
	: numparticipants_(numparticipants < 16 ? numparticipants : 16) {
}

Decoder_String_Vector::~Decoder_String_Vector() {
}

void Decoder_String_Vector::decode(const PCars_Data & data, Position & position) {

	for (int8_t i = 0; i < numparticipants_; ++i) {
		Decoder_64Char cdecoder;
		cdecoder.decode(data, position);
		stringvector_.push_back(cdecoder.char64());
	}


	position += (numparticipants_ * 64);
}

Vector_String Decoder_String_Vector::string_vector() const {
	return stringvector_;
}


}
