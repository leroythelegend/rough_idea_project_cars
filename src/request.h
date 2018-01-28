#ifndef PCARS_REQUEST_H_
#define PCARS_REQUEST_H_

#include <memory>

#include "decoder.h"

namespace pcars {

class Request {
public:
	virtual ~Request() {}

	virtual bool request(Decoder *) = 0;
};

}

#endif
