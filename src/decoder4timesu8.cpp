#include "decoder4timesu8.h"

namespace pcars {

Decoder_4Times_U8::Decoder_4Times_U8() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);

}

Vector_U8 Decoder_4Times_U8::times4_u8() const {
	Vector_U8 value;
	value.push_back(first_.u8());
	value.push_back(second_.u8());
	value.push_back(third_.u8());
	value.push_back(forth_.u8());
	return value;
}

}

