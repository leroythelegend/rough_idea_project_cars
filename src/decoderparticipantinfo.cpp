#include "decoderparticipantinfo.h"

namespace pcars {

Decoder_Participant_Info::Decoder_Participant_Info() {
	add(&worldposition_);
	add(&currentlapdistance_);
	add(&raceposition_);
	add(&lapscompleted_);
	add(&currentlap_);
	add(&sector_);
	add(&lastsectortime_);

}

Decoder_Participant_Info::~Decoder_Participant_Info() {
}

Vector_Float Decoder_Participant_Info::world_position() const {
	Vector_S16 rvalue = worldposition_.times3_s16();
	Vector_Float value;
	value.push_back(rvalue.at(0));
	value.push_back(rvalue.at(1));
	value.push_back(rvalue.at(2));
	return value;
}

unsigned int Decoder_Participant_Info::current_lap_distance() const {
	return currentlapdistance_.u16();
}

bool Decoder_Participant_Info::is_active() const {
	return raceposition_.msb_bool();
}

unsigned int Decoder_Participant_Info::race_position() const {
	return raceposition_.ls7_bits();
}

bool Decoder_Participant_Info::lap_invalidated() const {
	return lapscompleted_.msb_bool();
}

uint8_t Decoder_Participant_Info::laps_completed() const {
	return lapscompleted_.ls7_bits();
}

unsigned int Decoder_Participant_Info::current_lap() const {
	return static_cast<unsigned int>(currentlap_.u8());
}

bool Decoder_Participant_Info::same_class() const {
	return sector_.msb_1bit();
}

unsigned int Decoder_Participant_Info::world_positionZ() const {
	return sector_.top_2bit();
}

unsigned int Decoder_Participant_Info::world_positionX() const {
	return sector_.bottom_2bit();
}

unsigned int Decoder_Participant_Info::sector() const {
	return sector_.lsb_3bit();
}

float Decoder_Participant_Info::last_sector_time() const {
	return lastsectortime_.f32();
}




}

