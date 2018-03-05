#include "dataparticipantsinfoformat2.h"

namespace pcars {


Data_Participants_Info_Format_2::Data_Participants_Info_Format_2(const Packet& packet) 
	: packet_{packet} {}

Vector_Int Data_Participants_Info_Format_2::world_position(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).world_position();
}

Vector_Int Data_Participants_Info_Format_2::orientation(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).orientation();
}

unsigned int Data_Participants_Info_Format_2::current_lap_distance(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).current_lap_distance();
}

unsigned int Data_Participants_Info_Format_2::race_position(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).race_position();
}

bool Data_Participants_Info_Format_2::is_active(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).is_active();
}

unsigned int Data_Participants_Info_Format_2::world_positionZ(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).world_position().at(0);
}

unsigned int Data_Participants_Info_Format_2::world_positionX(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).world_position().at(2);
}

unsigned int Data_Participants_Info_Format_2::sector(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).sector();
}

unsigned int Data_Participants_Info_Format_2::flag_colour(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).flag_colour();
}

unsigned int Data_Participants_Info_Format_2::flag_reason(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).flag_reason();
}

unsigned int Data_Participants_Info_Format_2::pit_mode(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).pit_mode();
}

unsigned int Data_Participants_Info_Format_2::pit_schedule(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).pit_mode_schedule();
}

bool Data_Participants_Info_Format_2::local_player(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).local_player();
}

bool Data_Participants_Info_Format_2::remote_player(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).remote_player();
}

bool Data_Participants_Info_Format_2::human_player(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).human_player();
}

bool Data_Participants_Info_Format_2::none_human_player(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).none_human_player();
}

unsigned int Data_Participants_Info_Format_2::car_index(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).car_index();
}

bool Data_Participants_Info_Format_2::lap_invalidated(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).invalid_lap();
}

unsigned int Data_Participants_Info_Format_2::race_state(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).race_state();
}

unsigned int Data_Participants_Info_Format_2::current_lap(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).current_lap();
}

float Data_Participants_Info_Format_2::current_time(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).current_time();
}

float Data_Participants_Info_Format_2::current_sector_time(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).current_sector_time();
}

unsigned int Data_Participants_Info_Format_2::laps_completed(const Participant participant) const {
	return packet_.timing_data().partcipants().at(participant).current_lap() - 1;
}

bool Data_Participants_Info_Format_2::same_class(const Participant) const {
	return false;
}

unsigned int Data_Participants_Info_Format_2::participant_index() const {
	return packet_.timing_data().local_participant_index();
}

Data_Participants_Info_Format_2::Participants Data_Participants_Info_Format_2::participants() const {
	return packet_.timing_data().num_participants();
}

}

