#include "requestpackagetelemetryv2.h"

#include <iostream>
#include <exception>

#include "dataformat2.h"

namespace pcars {

Request_Package_Telemetry_V2::Request_Package_Telemetry_V2(Process * process, Live * live)
	: recordlap_{process},
	  recordlive_{live},
	  practice_{&recordlap_}, 
	  qualy_{&recordlive_, &practice_}, 
	  race_{&recordlive_, &qualy_} {}

bool Request_Package_Telemetry_V2::request(const PCars_Data & packet) {

	try {
		Position pos = 0;
		packet_.decode(packet, pos);	

		Data_Format_2 data(&packet_);

		return race_.request(&data);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << std::endl;
		return false;
	}
	catch (...) {
		std::cerr << "Unknown error: " << std::endl;
		return false;
	}

	return true;
}


}

