#ifndef PCARS_REQUEST_PACKAGE_H_
#define PCARS_REQUEST_PACKAGE_H_

#include <memory>

#include "consts.h"
#include "process.h"

namespace pcars {

class Request_Package {
public:
	virtual ~Request_Package() {}

	virtual bool request(const PCars_Data &) = 0;
};

}

#endif

