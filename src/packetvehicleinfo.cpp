#include "packetvehicleinfo.h"

namespace pcars {


Packet_Vehicle_Info::Packet_Vehicle_Info() {
	add(&index_);
	add(&class_);
	add(&name_);
}

unsigned int Packet_Vehicle_Info::index() const {
	return index_.u16();
}

unsigned int Packet_Vehicle_Info::class_name() const {
	return class_.u32();
}

std::string Packet_Vehicle_Info::name() const {
	return name_.char64();
}

}

