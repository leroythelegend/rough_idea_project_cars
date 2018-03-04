#ifndef PCARS_PACKET_PARTICIPANT_INFO_H_
#define PCARS_PACKET_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoderf32.h"
#include "decoderu8.h"
#include "decoder3bit3bit.h"
#include "decoderboolu8.h"

namespace pcars {

class Packet_Participant_Info : public Decoder_Composite {
public:

	Packet_Participant_Info();
	virtual ~Packet_Participant_Info() {}

	Vector_Int world_position();
	Vector_Int orientation();
	unsigned int current_lap_distance();
	unsigned int race_position();
	bool is_active();
	unsigned int sector();
	unsigned int flag_colour();
	unsigned int flag_reason();
	unsigned int pit_mode();
	unsigned int pit_mode_schedule();
	unsigned int car_index();
	bool local_player();
	bool remote_player();
	bool human_player();
	bool none_human_player();
	unsigned int race_state();
	bool invalid_lap();
	unsigned int current_lap();
	float current_time();
	float current_sector_time();
	unsigned int mp_participant_index();

private:
	Decoder_3Times_S16 world_position_;
	Decoder_3Times_S16 orientation_;
	Decoder_U16 current_lap_distance_;
	Decoder_Bool_U8 race_position_;
	Decoder_U8 sector_;
	Decoder_3bit_3bit highest_flag_;
	Decoder_3bit_3bit pit_mode_schedule_;
	Decoder_Bool_U8 car_index_;
	Decoder_Bool_U8 race_state_;
	Decoder_U8 current_lap_;
	Decoder_F32 current_time_;
	Decoder_F32 current_sector_time_;
	Decoder_U16 mp_participant_index_;
};

}

#endif

