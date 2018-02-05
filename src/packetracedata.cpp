#include "packetracedata.h"

namespace pcars {

Packet_Race_Data::Packet_Race_Data() {
	add(&packet_base_);		
	add(&world_fastest_lap_time_);
	add(&personal_fastest_lap_time_);	
	add(&personal_fastest_sector1_time_);
	add(&personal_fastest_sector2_time_);
	add(&personal_fastest_sector3_time_);
	add(&world_fastest_sector1_time_);
	add(&world_fastest_sector2_time_);
	add(&world_fastest_sector3_time_);
	add(&track_length_);
	add(&track_location_);	
	add(&track_variation_);	
	add(&translated_track_location_);
	add(&translated_track_variation_);
	add(&laps_time_in_event_);
	add(&enforced_pitstop_lap_);
}

Packet_Base Packet_Race_Data::packet_base() const {
	return packet_base_;
}

float Packet_Race_Data::world_fastest_lap_time() const {
	return world_fastest_lap_time_.f32();
}

float Packet_Race_Data::personal_fastest_lap_time() const {
	return personal_fastest_lap_time_.f32();
}

float Packet_Race_Data::personal_fastest_sector1_time() const {
	return personal_fastest_sector1_time_.f32();
}

float Packet_Race_Data::personal_fastest_sector2_time() const {
	return personal_fastest_sector2_time_.f32();
}

float Packet_Race_Data::personal_fastest_sector3_time() const {
	return personal_fastest_sector3_time_.f32();
}

float Packet_Race_Data::world_fastest_sector1_time() const {
	return world_fastest_sector1_time_.f32();
}

float Packet_Race_Data::world_fastest_sector2_time() const {
	return world_fastest_sector2_time_.f32();
}

float Packet_Race_Data::world_fastest_sector3_time() const {
	return world_fastest_sector3_time_.f32();
}

float Packet_Race_Data::track_length() const {
	return track_length_.f32();
}

std::string Packet_Race_Data::track_location() const {
	return track_location_.char64();
}

std::string Packet_Race_Data::track_variation() const {
	return track_variation_.char64();
}

std::string Packet_Race_Data::translated_track_location() const {
	return translated_track_location_.char64();
}

std::string Packet_Race_Data::translated_track_variation() const {
	return translated_track_variation_.char64();
}

unsigned int Packet_Race_Data::laps_time_in_event() const {
	return laps_time_in_event_.u16();
}

int Packet_Race_Data::enforced_pitstop_lap() const {
	return enforced_pitstop_lap_.s8();
}

}

