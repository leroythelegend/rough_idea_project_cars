#include "decoder56participantinfo.h"

namespace pcars {

Decoder_56_Participant_Info::Decoder_56_Participant_Info() 
	: particpantsinfo_(56) {
	for (unsigned int i = 0; i < particpantsinfo_.size(); ++i) {
		add(&particpantsinfo_.at(i));
	}
}

Decoder_56_Participant_Info::Vector_Participant_Info Decoder_56_Participant_Info::participant_info() const {
	return particpantsinfo_;
}

}
