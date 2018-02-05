#include "packet16vehicleinfo.h"

namespace pcars {

Packet_16_Vehicle_Info::Packet_16_Vehicle_Info()
	: vehicle_info_(16) {
	for (unsigned int i = 0; i < vehicle_info_.size(); ++i) {
		add(&vehicle_info_.at(i));
	}
}

Packet_16_Vehicle_Info::Vector_Vehicle_Info Packet_16_Vehicle_Info::vehicle_info() const {
	return vehicle_info_;
}

}

