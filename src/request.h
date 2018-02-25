#ifndef PCARS_REQUEST_H_
#define PCARS_REQUEST_H_

#include <memory>

#include "data.h"

namespace pcars {

class Request {
public:
	virtual ~Request() {}

	virtual bool request(Data *) = 0;
};

}

#endif
