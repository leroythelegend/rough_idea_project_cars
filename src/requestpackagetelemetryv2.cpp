#include "requestpackagetelemetryv2.h"

#include <iostream>
#include <exception>

#include "dataformat2.h"
#include "packet.h"

namespace pcars {

Request_Package_Telemetry_V2::Request_Package_Telemetry_V2(Process * process, Live * live, Process_Session * session)
	: post_lap_{process},
	  live_{live},
	  session_{session},
	  session_result_{session},
	  race_not_in_pits_{&live_},
	  race_{nullptr, &race_not_in_pits_},
	  qualy_not_in_pits_{&live_},
	  qualy_{nullptr, &qualy_not_in_pits_},
	  practice_racing_{&post_lap_},
	  practice_{nullptr, &practice_racing_},
	  practice_not_in_pits_{&live_},
	  practice_live_{nullptr, &practice_not_in_pits_},
	  practice_capture_decision_{&session_},
	  pracitice_decision_{nullptr,&practice_capture_decision_}, 
	  pracitice_decision_result_{&session_result_},
	  pracitice_result_{nullptr, &pracitice_decision_result_} {} 

bool Request_Package_Telemetry_V2::request(const PCars_Data & packet) {

	try {
		Position pos = 0;
		packet_.decode(packet, pos);	

		std::shared_ptr<Data> data = std::make_shared<Data_Format_2>(packet_);

		race_.request(data);
		qualy_.request(data);	
		practice_.request(data);
		//practice_live_.request(data);
		pracitice_decision_.request(data);
		pracitice_result_.request(data);

		return true;
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

