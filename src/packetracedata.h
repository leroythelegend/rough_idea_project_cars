#ifndef PCARS_PACKET_RACE_DATA_H_
#define PCARS_PACKET_RACE_DATA_H_

#include <string>

#include "decodercomposite.h"

#include "consts.h"

#include "packetbase.h"
#include "packet32participantinfo.h"

#include "decoderu16.h"
#include "decoderf32.h"
#include "decoders8.h"
#include "decoder64char.h"

namespace pcars {

class Packet_Race_Data : public Decoder_Composite {
public:

	Packet_Race_Data();
	virtual ~Packet_Race_Data() {}

	Packet_Base packet_base() const;		
	float world_fastest_lap_time() const;
	float personal_fastest_lap_time() const;	
	float personal_fastest_sector1_time() const;
	float personal_fastest_sector2_time() const;
	float personal_fastest_sector3_time() const;
	float world_fastest_sector1_time() const;
	float world_fastest_sector2_time() const;
	float world_fastest_sector3_time() const;
	float track_length() const;
	std::string track_location() const;	
	std::string track_variation() const;	
	std::string translated_track_location() const;
	std::string translated_track_variation() const;
	unsigned int laps_time_in_event() const;
	int enforced_pitstop_lap() const;

private:

	Packet_Base packet_base_;		
	Decoder_F32 world_fastest_lap_time_;
	Decoder_F32 personal_fastest_lap_time_;	
	Decoder_F32 personal_fastest_sector1_time_;
	Decoder_F32 personal_fastest_sector2_time_;
	Decoder_F32 personal_fastest_sector3_time_;
	Decoder_F32 world_fastest_sector1_time_;
	Decoder_F32 world_fastest_sector2_time_;
	Decoder_F32 world_fastest_sector3_time_;
	Decoder_F32 track_length_;
	Decoder_64Char track_location_;	
	Decoder_64Char track_variation_;	
	Decoder_64Char translated_track_location_;
	Decoder_64Char translated_track_variation_;
	Decoder_U16 laps_time_in_event_;
	Decoder_S8 enforced_pitstop_lap_;

};

}

#endif

