#include "decoder16timeschar64.h"

namespace pcars {

Decoder_16Times_64Char::Decoder_16Times_64Char() {
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

Vector_String Decoder_16Times_64Char::times16_64Char() const {
	Vector_String value;
	value.push_back(first_.char64());
	value.push_back(second_.char64());
	value.push_back(third_.char64());
	value.push_back(forth_.char64());
	value.push_back(fith_.char64());
	value.push_back(sixth_.char64());
	value.push_back(seventh_.char64());
	value.push_back(eightth_.char64());
	value.push_back(nineth_.char64());
	value.push_back(tenth_.char64());
	value.push_back(eleventh_.char64());
	value.push_back(twelve_.char64());
	value.push_back(thirteen_.char64());
	value.push_back(forteen_.char64());
	value.push_back(fithteen_.char64());
	value.push_back(sixteen_.char64());
	return value;
}

}

