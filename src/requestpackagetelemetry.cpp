#include "requestpackagetelemetry.h"

#include <iostream>
#include <exception>

#include "decodergeneric.h"
#include "decodertelemetrydata.h"

namespace pcars {

Request_Package_Telemetry::Request_Package_Telemetry(Request_Package * request)
	: request_{request},
	  racing_{&record_} {}

bool Request_Package_Telemetry::request(const PCars_Data & packet) {

	Decoder_Generic gdecoder;

	try {
		unsigned int pos = 0;
		gdecoder.decode(packet, pos);
		pos = 0; // reset pos after decode

		if (gdecoder.packet_type() == Packet_Type::PACKET_TYPE_TELEMETRY) {

			Decoder_Telemetry_Data decoder;
			decoder.decode(packet, pos);

			// Build Version 1200 decoder.build_version();

			return racing_.request(&decoder);
		}

		if (request_) {
			return request_->request(packet);
		}
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

