#include "packetparticipantinfo.h"

namespace pcars {
	
Packet_Participant_Info::Packet_Participant_Info() {
	add(&world_position_);
	add(&orientation_);
	add(&current_lap_distance_);
	add(&race_position_);
	add(&sector_);
	add(&highest_flag_);
	add(&pit_mode_schedule_);
	add(&car_index_);
	add(&race_state_);
	add(&current_lap_);
	add(&current_time_);
	add(&current_sector_time_);
	add(&mp_participant_index_);
}

Vector_Int Packet_Participant_Info::world_position() {
	return world_position_.times3_s16();
}

Vector_Int Packet_Participant_Info::orientation() {
	return orientation_.times3_s16();
}

unsigned int Packet_Participant_Info::current_lap_distance() {
	return current_lap_distance_.u16();
}

bool Packet_Participant_Info::is_active() {
	return race_position_.msb_bool();
}

unsigned int Packet_Participant_Info::race_position() {
	return race_position_.ls7_bits();
}

unsigned int Packet_Participant_Info::sector() {
	return sector_.u8();
}

unsigned int Packet_Participant_Info::flag_colour() {
	return highest_flag_.ms3bits();
}

unsigned int Packet_Participant_Info::flag_reason() {
	return highest_flag_.ls3bits();
}
unsigned int Packet_Participant_Info::pit_mode() {
	return pit_mode_schedule_.ms3bits();
}

unsigned int Packet_Participant_Info::pit_mode_schedule() {
	return pit_mode_schedule_.ls3bits();
}

unsigned int Packet_Participant_Info::car_index() {
	return car_index_.ls7_bits();
}

bool Packet_Participant_Info::local_player() {
	return car_index_.msb_bool();
}

bool Packet_Participant_Info::remote_player() {
	return car_index_.msb_bool();
}

bool Packet_Participant_Info::human_player() {
	return car_index_.msb_bool();
}

bool Packet_Participant_Info::none_human_player() {
	return car_index_.msb_bool();
}

unsigned int Packet_Participant_Info::race_state() {
	return race_state_.ls7_bits();
}

bool Packet_Participant_Info::invalid_lap() {
	return car_index_.msb_bool();
}

unsigned int Packet_Participant_Info::current_lap() {
	return current_lap_.u8();
}

float Packet_Participant_Info::current_time() {
	return current_time_.f32();
}

float Packet_Participant_Info::current_sector_time() {
	return current_sector_time_.f32();
}

unsigned int Packet_Participant_Info::mp_participant_index() {
	return mp_participant_index_.u16();
}

}


