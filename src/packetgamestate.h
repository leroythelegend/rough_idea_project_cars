#ifndef PCARS_PACKET_GAME_STATE_H_
#define PCARS_PACKET_GAME_STATE_H_

#include "decodercomposite.h"

#include "packetbase.h"

#include "decoderu16.h"
#include "decoder3bit3bit.h"
#include "decoders8.h"
#include "decoderu8.h"

namespace pcars {

class Packet_Game_State : public Decoder_Composite {
public:
	Packet_Game_State();
	virtual ~Packet_Game_State() {}

	Packet_Base packet_base() const;
	unsigned int build_version() const;
	unsigned int game_state() const;
	unsigned int sessin_state() const;
	int ambient_temperature() const;
	int track_temperature() const;
	unsigned int rain_density() const;
	unsigned int snow_density() const;
	int wind_speed() const;
	int wind_direction_x() const;
	int wind_direction_y() const;

private:
	Packet_Base packet_base_;
	Decoder_U16 build_version_;
	Decoder_3bit_3bit game_session_state_;
	Decoder_S8 ambient_temperature_;
	Decoder_S8 track_temperature_;
	Decoder_U8 rain_density_;
	Decoder_U8 snow_density_;
	Decoder_S8 wind_speed_;
	Decoder_S8 wind_direction_x_;
	Decoder_S8 wind_direction_y_;
};

}

#endif

