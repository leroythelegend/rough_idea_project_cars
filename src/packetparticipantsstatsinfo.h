#ifndef PCARS_PACKET_PARTICIPANTS_STATS_INFO_H_
#define PCARS_PACKET_PARTICIPANTS_STATS_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoderu16.h"
#include "decoderu32.h"
#include "decoderf32.h"

namespace pcars {

class Packet_Participants_Stats_Info : public Decoder_Composite {
public:

	Packet_Participants_Stats_Info();
	virtual ~Packet_Participants_Stats_Info() {}

	float fastest_lap_time() const;
	float last_lap_time() const;
	float last_sector_time() const;
	float fastest_sector1_time() const;
	float fastest_sector2_time() const;
	float fastest_sector3_time() const;
	unsigned int participant_online_rep() const;
	unsigned int  mp_participant_index() const;

private:
	Decoder_F32 fastest_lap_time_;
	Decoder_F32 last_lap_time_;
	Decoder_F32 last_sector_time_;
	Decoder_F32 fastest_sector1_time_;
	Decoder_F32 fastest_sector2_time_;
	Decoder_F32 fastest_sector3_time_;
	Decoder_U32 participant_online_rep_;
	Decoder_U16 mp_participant_index_;

};

}

#endif

