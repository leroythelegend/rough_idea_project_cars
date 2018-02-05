#ifndef PCARS_PACKET_32_PARTICIPANT_INFO_H_
#define PCARS_PACKET_32_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "packetparticipantinfo.h"

namespace pcars {

class Packet_32_Participant_Info : public Decoder_Composite {
public:
	using Vector_Participant_Info = std::vector<Packet_Participant_Info>;

	Packet_32_Participant_Info();
	virtual ~Packet_32_Participant_Info() {}

	Vector_Participant_Info participant_info() const;

private:

	Vector_Participant_Info particpantsinfo_;
};

}

#endif

