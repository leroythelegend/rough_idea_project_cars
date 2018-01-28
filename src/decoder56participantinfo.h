#ifndef PCARS_DECODER_56_PARTICIPANT_INFO_H_
#define PCARS_DECODER_56_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "decoderparticipantinfo.h"

namespace pcars {

class Decoder_56_Participant_Info : public Decoder_Composite {
public:
	using Vector_Participant_Info = std::vector<Decoder_Participant_Info>;

	Decoder_56_Participant_Info();
	virtual ~Decoder_56_Participant_Info() {}

	Vector_Participant_Info participant_info() const;

private:

	Vector_Participant_Info particpantsinfo_;
};

}

#endif

