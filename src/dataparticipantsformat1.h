#ifndef PCARS_DATA_PERTICIPANTS_FORMAT_1_H_
#define PCARS_DATA_PERTICIPANTS_FORMAT_1_H_

#include "dataparticipants.h"

namespace pcars {

class Data_Participants_Format_1 : public Data_Participants {
public:
	using Participant = unsigned int;
	using Participants = unsigned int;

	Data_Participants_Format_1();
	virtual ~Data_Participants_Format_1() {}

	std::string name(Participant) const override;
	unsigned int nationality(Participant) const override;
	unsigned int index(Participant) const override;
};

}

#endif

