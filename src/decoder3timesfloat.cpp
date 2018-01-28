#include "decoder3timesfloat.h"

namespace pcars {

Decoder_3Times_Float::Decoder_3Times_Float() {
	add(&first_);
	add(&second_);
	add(&third_);
}

Vector_Float Decoder_3Times_Float::times3_float() const {
	Vector_Float value;
	value.push_back(first_.f32());
	value.push_back(second_.f32());
	value.push_back(third_.f32());
	return value;
}

}

