#ifndef PCARS_PACKET_TIME_STATS_DATA_H_
#define PCARS_PACKET_TIME_STATS_DATA_H_

#include "decodercomposite.h"

#include "consts.h"

#include "packetbase.h"

#include "decoderu32.h"
#include "packet32participantsstatsinfo.h"

namespace pcars {

class Packet_Time_Stats_Data : public Decoder_Composite {
public:

	Packet_Time_Stats_Data();
	virtual ~Packet_Time_Stats_Data() {}

	Packet_Base packet_base() const;		
	unsigned int participants_changed_timestamp() const;
	Packet_32_Participants_Stats_Info::Vector_Participants_Stats_Info stats() const;

private:

	Packet_Base packet_base_;		
	Decoder_U32 participants_changed_timestamp_;
	Packet_32_Participants_Stats_Info stats_;
};

}

#endif

