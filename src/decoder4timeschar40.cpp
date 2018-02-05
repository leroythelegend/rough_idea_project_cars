#include "decoder4timeschar40.h"

namespace pcars {

Decoder_4Times_40Char::Decoder_4Times_40Char() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);
}

Vector_String Decoder_4Times_40Char::times4_40Char() const {
	Vector_String value;
	value.push_back(first_.char40());
	value.push_back(second_.char40());
	value.push_back(third_.char40());
	value.push_back(forth_.char40());
	return value;
}

}

