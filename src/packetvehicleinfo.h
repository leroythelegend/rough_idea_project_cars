#ifndef PCARS_PACKET_VEHICLE_INFO_H_
#define PCARS_PACKET_VEHICLE_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoderu32.h"
#include "decoderu16.h"
#include "decoder64char.h"

namespace pcars {

class Packet_Vehicle_Info : public Decoder_Composite {
public:

	Packet_Vehicle_Info();
	virtual ~Packet_Vehicle_Info() {}

	unsigned int index() const;
	unsigned int class_name() const;
	std::string name() const;

private:
	Decoder_U16 index_;
	Decoder_U32 class_;
	Decoder_64Char name_;
};

}

#endif

