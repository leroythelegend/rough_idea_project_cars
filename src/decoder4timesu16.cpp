#include "decoder4timesu16.h"

namespace pcars {

Decoder_4Times_U16::Decoder_4Times_U16() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);
}

Vector_U16 Decoder_4Times_U16::times4_u16() const {
	Vector_U16 value;
	value.push_back(first_.u16());
	value.push_back(second_.u16());
	value.push_back(third_.u16());
	value.push_back(forth_.u16());
	return value;
}

}
