#include "decoder16timesu16.h"

namespace pcars {

Decoder_16Times_U16::Decoder_16Times_U16() {
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

Vector_UInt Decoder_16Times_U16::times16_u16() const {
	Vector_UInt value;
	value.push_back(first_.u16());
	value.push_back(second_.u16());
	value.push_back(third_.u16());
	value.push_back(forth_.u16());
	value.push_back(fith_.u16());
	value.push_back(sixth_.u16());
	value.push_back(seventh_.u16());
	value.push_back(eightth_.u16());
	value.push_back(nineth_.u16());
	value.push_back(tenth_.u16());
	value.push_back(eleventh_.u16());
	value.push_back(twelve_.u16());
	value.push_back(thirteen_.u16());
	value.push_back(forteen_.u16());
	value.push_back(fithteen_.u16());
	value.push_back(sixteen_.u16());
	return value;
}

}

