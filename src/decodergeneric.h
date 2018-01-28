#ifndef PCARS_DECODER_GENERIC_H_
#define PCARS_DECODER_GENERIC_H_

#include "decodercomposite.h"

#include "decoderu16.h"
#include "decoder6bit2bit.h"

namespace pcars {

class Decoder_Generic : public Decoder_Composite {
public:
	Decoder_Generic();
	virtual ~Decoder_Generic();

	uint16_t build_version() const;
	unsigned int sequence_number() const;
	Packet_Type packet_type() const;

private:
	Decoder_U16 buildversion_;
	Decoder_6bit_2bit sequencenum_packettype_;
};

}

#endif

