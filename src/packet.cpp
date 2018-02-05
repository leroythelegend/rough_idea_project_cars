#include "packet.h"

#include "packetbase.h"
#include "consts.h"

namespace pcars {

void Packet::decode(const PCars_Data & data, Position & )  {

	Packet_Base base;
	Position pos = 0;
	base.decode(data, pos);

	switch (static_cast<Packet_Type_V2>(base.packet_type())) {
		case Packet_Type_V2::PACKET_CAR_PHYSICS:
			pos = 0;
			telemetry_data_.decode(data, pos);
			break;
		case Packet_Type_V2::PACKET_GAME_STATE:
			pos = 0;
			game_state_.decode(data,pos);
			break;
		case Packet_Type_V2::PACKET_TIMINGS:
			pos = 0;
			timing_data_.decode(data,pos);
			break;
		case Packet_Type_V2::PACKET_RACE_DEFINITION:
			pos = 0;
			race_data_.decode(data,pos);
			break;
		case Packet_Type_V2::PACKET_PARTICIPANTS: {
			if (base.partial_packet_index() == 1) {
				pos = 0;
				participants_data_.decode(data,pos);
			}
			else if (base.partial_packet_index() == 2) { 
				pos = 0;
				participants_data_2_.decode(data,pos);
			}
			break;
		}
		case Packet_Type_V2::PACKET_TIME_STATS:
			pos = 0;
			time_stats_data_.decode(data,pos);
			break;
		case Packet_Type_V2::PACKET_PARTICIPANT_VEHICLE_NAMES: {
			if (base.partial_packet_index() == 1) {
				pos = 0;
				vehicle_names_.decode(data,pos);
			}
			else if (base.partial_packet_index() == 2) { 
				pos = 0;
				vehicle_names_2_.decode(data,pos);
			}
			break;
		}
		default:
			break;
	}
}


const Packet_Game_State& Packet::game_state() const {
	return game_state_;
}

const Packet_Telemetry_Data& Packet::telemetry_data() const {
	return telemetry_data_;
}

const Packet_Timing_Data& Packet::timing_data() const {
	return timing_data_;
}

const Packet_Race_Data& Packet::race_data() const {
	return race_data_;
}

const Packet_Participants_Data& Packet::participants_data() const {
	return participants_data_;
}

const Packet_Participants_Data& Packet::participants_data_2() const {
	return participants_data_;
}

const Packet_Time_Stats_Data& Packet::time_stats_data() const {
	return time_stats_data_;
}

const Packet_Participants_Vehicle_Names_Data& Packet::vehicle_names() const {
	return vehicle_names_;
}

const Packet_Participants_Vehicle_Names_Data& Packet::vehicle_names_2() const {
	return vehicle_names_;
}


}

