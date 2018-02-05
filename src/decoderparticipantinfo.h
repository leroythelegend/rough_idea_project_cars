#ifndef PCARS_DEOCDER_PARTICIPANT_INFO_H_
#define PCARS_DEOCDER_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoder1bit2bit2bit3bit.h"
#include "decoderu8.h"
#include "decoderf32.h"
#include "decoderboolu8.h"

namespace pcars {

class Decoder_Participant_Info : public Decoder_Composite {
public:
	Decoder_Participant_Info();
	virtual ~Decoder_Participant_Info();

	Vector_Int world_position() const;
	unsigned int current_lap_distance() const;
	bool is_active() const;
	unsigned int race_position() const;
	bool lap_invalidated() const;
	unsigned int laps_completed() const;
	unsigned int current_lap() const;
	bool same_class() const;
	unsigned int world_positionZ() const;
	unsigned int world_positionX() const;
	unsigned int sector() const;
	float last_sector_time() const;

private:
	Decoder_3Times_S16 worldposition_;
	Decoder_U16 currentlapdistance_;
	Decoder_Bool_U8 raceposition_;
	Decoder_Bool_U8 lapscompleted_;
	Decoder_U8 currentlap_;
	Decoder_1bit_2bit_2bit_3bit sector_;
	Decoder_F32 lastsectortime_;

};

}

#endif

