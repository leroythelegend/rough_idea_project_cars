#include "decoder3timess16.h"

namespace pcars {

Decoder_3Times_S16::Decoder_3Times_S16() {
	add(&first_);
	add(&second_);
	add(&third_);
}

Vector_S16 Decoder_3Times_S16::times3_s16() const {
	Vector_S16 value;
	value.push_back(first_.s16());
	value.push_back(second_.s16());
	value.push_back(third_.s16());
	return value;
}

}
