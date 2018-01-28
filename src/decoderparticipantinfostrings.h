#ifndef PCARS_DECODER_PARTICIPANT_INFO_STRINGS_H_
#define PCARS_DECODER_PARTICIPANT_INFO_STRINGS_H_

#include "decodercomposite.h"
#include "decoderu16.h"
#include "decoder6bit2bit.h"
#include "decoder64char.h"
#include "decoderstringvector.h"

#include <string>
#include <vector>

namespace pcars {

class Decoder_Participant_Info_Strings : public Decoder_Composite {
public:
	using Num_Participants = int8_t;

	Decoder_Participant_Info_Strings(Num_Participants);
	virtual ~Decoder_Participant_Info_Strings();

        uint16_t build_version() const;
	unsigned int sequence_number() const;
	std::string car_name() const;
	std::string car_class_name() const;
	std::string track_location() const;
	std::string track_variation() const;
	Vector_String names() const;

private:
	Num_Participants numparticipants_;

        Decoder_U16 buildversion_;
	Decoder_6bit_2bit sequencenum_packettype_;
	Decoder_64Char carname_;
	Decoder_64Char carclassname_;
	Decoder_64Char tracklocation_;
	Decoder_64Char trackvariation_;
	Decoder_StringVector names_;
};

}

#endif

