#ifndef PCARS_DATA_TIMES_H_
#define PCARS_DATA_TIMES_H_

#include "consts.h"

namespace pcars {

class Data_Times {
public:
	virtual ~Data_Times() {}

	virtual float current_time() const = 0;
	virtual float current_sector1_time() const = 0;
	virtual float current_sector2_time() const = 0;
	virtual float current_sector3_time() const = 0;
	virtual float fastest_sector1_time() const = 0;
	virtual float fastest_sector2_time() const = 0;
	virtual float fastest_sector3_time() const = 0;
};

}

#endif

