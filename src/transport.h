#ifndef PCARS_TRANSPORT_H_
#define PCARS_TRANSPORT_H_

#include "consts.h"

namespace pcars {

class Transport {
public:
	virtual ~Transport() {};

	virtual PCars_Data read(const Amount) = 0;
	virtual void write(const PCars_Data &) = 0;
};

}

#endif
