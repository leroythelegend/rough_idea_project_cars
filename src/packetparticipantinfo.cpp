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

Vector_Int Packet_Participant_Info::world_position() const {
	return world_position_.times3_s16();
}

Vector_Int Packet_Participant_Info::orientation() const {
	return orientation_.times3_s16();
}

unsigned int Packet_Participant_Info::current_lap_distance() const {
	return current_lap_distance_.u16();
}

bool Packet_Participant_Info::is_active() const {
	return race_position_.msb_bool();
}

unsigned int Packet_Participant_Info::race_position() const {
	return race_position_.ls7_bits();
}

unsigned int Packet_Participant_Info::sector() const {
	return sector_.u8();
}

unsigned int Packet_Participant_Info::flag_colour() const {
	return highest_flag_.ms3bits();
}

unsigned int Packet_Participant_Info::flag_reason() const {
	return highest_flag_.ls3bits();
}
unsigned int Packet_Participant_Info::pit_mode() const {
	return pit_mode_schedule_.ms3bits();
}

unsigned int Packet_Participant_Info::pit_mode_schedule() const {
	return pit_mode_schedule_.ls3bits();
}

unsigned int Packet_Participant_Info::car_index() const {
	return car_index_.ls7_bits();
}

bool Packet_Participant_Info::local_player() const {
	return car_index_.msb_bool();
}

bool Packet_Participant_Info::remote_player() const {
	return car_index_.msb_bool();
}

bool Packet_Participant_Info::human_player() const {
	return car_index_.msb_bool();
}

bool Packet_Participant_Info::none_human_player() const {
	return car_index_.msb_bool();
}

unsigned int Packet_Participant_Info::race_state() const {
	return race_state_.ls7_bits();
}

bool Packet_Participant_Info::invalid_lap() const {
	return car_index_.msb_bool();
}

unsigned int Packet_Participant_Info::current_lap() const {
	return current_lap_.u8();
}

float Packet_Participant_Info::current_time() const {
	return current_time_.f32();
}

float Packet_Participant_Info::current_sector_time() const {
	return current_sector_time_.f32();
}

unsigned int Packet_Participant_Info::mp_participant_index() const {
	return mp_participant_index_.u16();
}

}


