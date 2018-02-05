#ifndef PCARS_PACKET_32_PARTICIPANTS_STATS_INFO_H_
#define PCARS_PACKET_32_PARTICIPANTS_STATS_INFO_H_

#include "decodercomposite.h"

#include "packetparticipantsstatsinfo.h"

namespace pcars {

class Packet_32_Participants_Stats_Info : public Decoder_Composite {
public:
	using Vector_Participants_Stats_Info = std::vector<Packet_Participants_Stats_Info>;

	Packet_32_Participants_Stats_Info();
	virtual ~Packet_32_Participants_Stats_Info() {}

	Vector_Participants_Stats_Info participants_stats_info() const;

private:

	Vector_Participants_Stats_Info particpants_stats_info_;
};

}

#endif

