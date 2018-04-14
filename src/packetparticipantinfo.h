#ifndef PCARS_PACKET_PARTICIPANT_INFO_H_
#define PCARS_PACKET_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoderf32.h"
#include "decoderu8.h"
#include "decoder3bit3bit.h"
#include "decoder4bit4bit.h"
#include "decoderboolu8.h"
#include "decoderboolu16.h"
#include "decoder4bit4bit.h"

namespace pcars {

class Packet_Participant_Info : public Decoder_Composite {
public:

	Packet_Participant_Info();
	virtual ~Packet_Participant_Info() {}

	Vector_Int world_position() const;
	Vector_Int orientation() const;
	unsigned int current_lap_distance() const;
	unsigned int race_position() const;
	bool is_active() const;
	unsigned int zx_position() const;
	unsigned int sector() const;
	unsigned int flag_colour() const;
	unsigned int flag_reason() const;
	unsigned int pit_mode() const;
	unsigned int pit_mode_schedule() const;
	unsigned int car_index() const;
	bool local_player() const;
	bool remote_player() const;
	bool human_player() const;
	bool none_human_player() const;
	unsigned int race_state() const;
	bool invalid_lap() const;
	unsigned int current_lap() const;
	float current_time() const;
	float current_sector_time() const;
	unsigned int mp_participant_index() const;

private:
	Decoder_3Times_S16 world_position_;
	Decoder_3Times_S16 orientation_;
	Decoder_U16 current_lap_distance_;
	Decoder_Bool_U8 race_position_;
	Decoder_4bit_4bit sector_;
	Decoder_3bit_3bit highest_flag_;
	Decoder_4bit_4bit pit_mode_schedule_;
	Decoder_Bool_U16 car_index_;
	Decoder_Bool_U8 race_state_;
	Decoder_U8 current_lap_;
	Decoder_F32 current_time_;
	Decoder_F32 current_sector_time_;
	Decoder_U16 mp_participant_index_;
};

}

#endif

