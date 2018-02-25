#ifndef PCARS_DATA_PERTICIPANTS_H_
#define PCARS_DATA_PERTICIPANTS_H_

#include "consts.h"

namespace pcars {

class Data_Participants {
public:
	virtual ~Data_Participants() {}

	virtual	Vector_String name() const = 0;
	virtual	unsigned int nationality() const = 0;
	virtual	unsigned int index() const = 0;
};

}

#endif

