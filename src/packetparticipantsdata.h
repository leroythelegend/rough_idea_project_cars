#ifndef PCARS_PACKET_PARTICIPANTS_DATA_H_
#define PCARS_PACKET_PARTICIPANTS_DATA_H_

#include "decodercomposite.h"

#include "consts.h"

#include "packetbase.h"

#include "decoderu16.h"
#include "decoderu32.h"
#include "decoder16timeschar64.h"
#include "decoder16timesu32.h"
#include "decoder16timesu16.h"

namespace pcars {

class Packet_Participants_Data : public Decoder_Composite {
public:

	Packet_Participants_Data();
	virtual ~Packet_Participants_Data() {}

	Packet_Base packet_base() const;		
	unsigned int participants_changed_timestamp() const;
	Vector_String name() const;
	Vector_UInt nationality() const;
	Vector_UInt index() const;

private:

	Packet_Base packet_base_;		
	Decoder_U32 participants_changed_timestamp_;
	Decoder_16Times_64Char name_;
	Decoder_16Times_U32 nationality_;
	Decoder_16Times_U16 index_;

};

}

#endif

