#include "packetparticipantsstatsinfo.h"

namespace pcars {

Packet_Participants_Stats_Info::Packet_Participants_Stats_Info() {
	add(&fastest_lap_time_);
	add(&last_lap_time_);
	add(&last_sector_time_);
	add(&fastest_sector1_time_);
	add(&fastest_sector2_time_);
	add(&fastest_sector3_time_);
	add(&participant_online_rep_);
	add(&mp_participant_index_);
}

float Packet_Participants_Stats_Info::fastest_lap_time() const {
	return fastest_lap_time_.f32();
}

float Packet_Participants_Stats_Info::last_lap_time() const {
	return last_lap_time_.f32();
}

float Packet_Participants_Stats_Info::last_sector_time() const {
	return last_sector_time_.f32();
}

float Packet_Participants_Stats_Info::fastest_sector1_time() const {
	return fastest_sector1_time_.f32();
}

float Packet_Participants_Stats_Info::fastest_sector2_time() const {
	return fastest_sector2_time_.f32();
}

float Packet_Participants_Stats_Info::fastest_sector3_time() const {
	return fastest_sector3_time_.f32();
}

unsigned int Packet_Participants_Stats_Info::participant_online_rep() const {
	return participant_online_rep_.u32();
}

unsigned int Packet_Participants_Stats_Info::mp_participant_index() const {
	return mp_participant_index_.u16();
}

}


