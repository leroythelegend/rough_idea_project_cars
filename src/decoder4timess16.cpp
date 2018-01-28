#include "decoder4timess16.h"

namespace pcars {

Decoder_4Times_S16::Decoder_4Times_S16() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);
}

Vector_S16 Decoder_4Times_S16::times4_s16() const {
	Vector_S16 value;
	value.push_back(first_.s16());
	value.push_back(second_.s16());
	value.push_back(third_.s16());
	value.push_back(forth_.s16());
	return value;
}

}
