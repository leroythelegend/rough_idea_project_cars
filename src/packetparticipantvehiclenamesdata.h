#ifndef PCARS_PACKET_PARTICIPANTS_VEHICLE_NAMES_DATA_H_
#define PCARS_PACKET_PARTICIPANTS_VEHICLE_NAMES_DATA_H_

#include "decodercomposite.h"

#include "consts.h"

#include "packetbase.h"

#include "decoderu32.h"
#include "packet16vehicleinfo.h"

namespace pcars {

class Packet_Participants_Vehicle_Names_Data : public Decoder_Composite {
public:

	Packet_Participants_Vehicle_Names_Data();
	virtual ~Packet_Participants_Vehicle_Names_Data() {}

	Packet_Base packet_base() const;		
	Packet_16_Vehicle_Info::Vector_Vehicle_Info vehicle_info() const;

private:
	Packet_Base packet_base_;		
	Packet_16_Vehicle_Info vehicle_info_;
};

}

#endif

