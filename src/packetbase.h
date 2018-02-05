#ifndef PCARS_PACKET_BASE_H_
#define PCARS_PACKET_BASE_H_

#include "decodercomposite.h"

#include "decoderu32.h"
#include "decoderu8.h"

namespace pcars {

class Packet_Base : public Decoder_Composite {
public:
	Packet_Base();
	virtual ~Packet_Base() {}

	unsigned int packet_number() const;
	unsigned int category_packet_number() const;
	unsigned int partial_packet_index() const;
	unsigned int partial_packet_number() const;
	unsigned int packet_type() const;
	unsigned int packet_version() const;
private:

	Decoder_U32 packet_number_;
	Decoder_U32 category_packet_number_;
	Decoder_U8 partial_packet_index_;
	Decoder_U8 partial_packet_number_;
	Decoder_U8 packet_type_;
	Decoder_U8 packet_version_;
};

}

#endif

