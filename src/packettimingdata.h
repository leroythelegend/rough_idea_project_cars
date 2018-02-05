#ifndef PCARS_PACKET_TIMING_DATA_H_
#define PCARS_PACKET_TIMING_DATA_H_

#include "decodercomposite.h"

#include "consts.h"

#include "packetbase.h"
#include "packet32participantinfo.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoderf32.h"
#include "decoders8.h"

namespace pcars {

class Packet_Timing_Data : public Decoder_Composite {
public:

	Packet_Timing_Data();
	virtual ~Packet_Timing_Data() {}

	Packet_Base packet_base() const;		
	int num_participants() const;
	unsigned int participants_changed_timestamp() const;
	float event_time_remaining() const;
	float split_time_ahead() const;
	float split_time_behind() const;
	float split_time() const;
	Packet_32_Participant_Info::Vector_Participant_Info partcipants() const;
	unsigned int local_participant_index() const;

private:

	Packet_Base packet_base_;		
	Decoder_S8 num_participants_;
	Decoder_U32 participants_changed_timestamp_;
	Decoder_F32 event_time_remaining_;
	Decoder_F32 split_time_ahead_;
	Decoder_F32 split_time_behind_;
	Decoder_F32 split_time_;
	Packet_32_Participant_Info partcipants_;
	Decoder_U16 local_participant_index_;
};

}

#endif

