#include "packetparticipantvehiclenamesdata.h"

namespace pcars {

Packet_Participants_Vehicle_Names_Data::Packet_Participants_Vehicle_Names_Data() {
	add(&packet_base_);
	add(&vehicle_info_);
}

Packet_Base Packet_Participants_Vehicle_Names_Data::packet_base() const {
	return packet_base_;
}

Packet_16_Vehicle_Info::Vector_Vehicle_Info Packet_Participants_Vehicle_Names_Data::vehicle_info() const {
	return vehicle_info_.vehicle_info();
}

}

