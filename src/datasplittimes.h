#ifndef PCARS_DATA_SPLIT_TIMES_H_
#define PCARS_DATA_SPLIT_TIMES_H_

#include "consts.h"

namespace pcars {

class Data_Split_Times {
public:
	virtual ~Data_Split_Times() {}

	virtual	unsigned int participants_changed_timestamp() const = 0;
	virtual	float event_time_remaining() const = 0;
	virtual	float split_time_ahead() const = 0;
	virtual	float split_time_behind() const = 0;
	virtual	float split_time() const = 0;
	virtual unsigned int tick_count() const = 0;
};

}

#endif

