#include "decoder2timesu8.h"

namespace pcars {

Decoder_2Times_U8::Decoder_2Times_U8() {
	add(&first_);
	add(&second_);

}

Decoder_2Times_U8::~Decoder_2Times_U8() {

}

Vector_UInt Decoder_2Times_U8::times2_U8() const {
	Vector_UInt value;
	value.push_back(first_.u8());
	value.push_back(second_.u8());
	return value;
}

}

