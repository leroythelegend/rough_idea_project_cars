#ifndef PCARS_DATA_PERTICIPANTS_H_
#define PCARS_DATA_PERTICIPANTS_H_

#include "consts.h"

namespace pcars {

class Data_Participants {
public:
	using Participant = unsigned int;
	using Participants = unsigned int;

	virtual ~Data_Participants() {}

	virtual	std::string name(Participant) const = 0;
	virtual	unsigned int nationality(Participant) const = 0;
	virtual	unsigned int index(Participant) const = 0;
};

}

#endif

