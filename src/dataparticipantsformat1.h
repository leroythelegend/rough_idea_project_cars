#ifndef PCARS_DATA_PERTICIPANTS_FORMAT_1_H_
#define PCARS_DATA_PERTICIPANTS_FORMAT_1_H_

#include "dataparticipants.h"

namespace pcars {

class Data_Participants_Format_1 : public Data_Participants {
public:
	Data_Participants_Format_1();
	virtual ~Data_Participants_Format_1() {}

	Vector_String name() const override;
	unsigned int nationality() const override;
	unsigned int index() const override;
};

}

#endif

