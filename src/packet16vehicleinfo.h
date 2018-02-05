#ifndef PCARS_PACKET_16_VEHICLE_INFO_H_
#define PCARS_PACKET_16_VEHICLE_INFO_H_

#include "decodercomposite.h"

#include "packetvehicleinfo.h"

namespace pcars {

class Packet_16_Vehicle_Info : public Decoder_Composite {
public:
	using Vector_Vehicle_Info = std::vector<Packet_Vehicle_Info>;

	Packet_16_Vehicle_Info();
	virtual ~Packet_16_Vehicle_Info() {}

	Vector_Vehicle_Info vehicle_info() const;

private:

	Vector_Vehicle_Info vehicle_info_;
};

}

#endif

