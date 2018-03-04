#ifndef PCARS_DATA_PERTICIPANTS_FORMAT_2_H_
#define PCARS_DATA_PERTICIPANTS_FORMAT_2_H_

#include "dataparticipants.h"
#include "packet.h"

namespace pcars {

class Data_Participants_Format_2 : public Data_Participants {
public:
	using Participant = unsigned int;
	using Participants = unsigned int;

	Data_Participants_Format_2(std::shared_ptr<Packet>);
	virtual ~Data_Participants_Format_2() {}

	std::string name(Participant) const override;
	unsigned int nationality(Participant) const override;
	unsigned int index(Participant) const override;

private:
	std::shared_ptr<Packet> packet_;
};

}

#endif

