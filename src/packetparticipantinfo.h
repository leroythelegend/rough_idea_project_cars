#ifndef PCARS_PACKET_PARTICIPANT_INFO_H_
#define PCARS_PACKET_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoderf32.h"
#include "decoderu8.h"

namespace pcars {

class Packet_Participant_Info : public Decoder_Composite {
public:

	Packet_Participant_Info();
	virtual ~Packet_Participant_Info() {}

	Vector_Int world_position();
	Vector_Int orientation();
	unsigned int current_lap_distance();
	unsigned int race_position();
	unsigned int sector();
	unsigned int highest_flag();
	unsigned int pit_mode_schedule();
	unsigned int car_index();
	unsigned int race_state();
	unsigned int current_lap();
	float current_time();
	float current_sector_time();
	unsigned int mp_participant_index();

private:
	Decoder_3Times_S16 world_position_;
	Decoder_3Times_S16 orientation_;
	Decoder_U16 current_lap_distance_;
	Decoder_U8 race_position_;
	Decoder_U8 sector_;
	Decoder_U8 highest_flag_;
	Decoder_U8 pit_mode_schedule_;
	Decoder_U16 car_index_;
	Decoder_U8 race_state_;
	Decoder_U8 current_lap_;
	Decoder_F32 current_time_;
	Decoder_F32 current_sector_time_;
	Decoder_U16 mp_participant_index_;
};

}

#endif

