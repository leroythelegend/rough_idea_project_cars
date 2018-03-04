#include "decoder16timesu32.h"

namespace pcars {

Decoder_16Times_U32::Decoder_16Times_U32() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);
	add(&fith_);
	add(&sixth_);
	add(&seventh_);
	add(&eightth_);
	add(&nineth_);
	add(&tenth_);
	add(&eleventh_);
	add(&twelve_);
	add(&thirteen_);
	add(&forteen_);
	add(&fithteen_);
	add(&sixteen_);

}

Vector_UInt Decoder_16Times_U32::times16_u32() const {
	Vector_UInt value;
	value.push_back(first_.u32());
	value.push_back(second_.u32());
	value.push_back(third_.u32());
	value.push_back(forth_.u32());
	value.push_back(fith_.u32());
	value.push_back(sixth_.u32());
	value.push_back(seventh_.u32());
	value.push_back(eightth_.u32());
	value.push_back(nineth_.u32());
	value.push_back(tenth_.u32());
	value.push_back(eleventh_.u32());
	value.push_back(twelve_.u32());
	value.push_back(thirteen_.u32());
	value.push_back(forteen_.u32());
	value.push_back(fithteen_.u32());
	value.push_back(sixteen_.u32());
	return value;
}

}

