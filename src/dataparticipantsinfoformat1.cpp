#include "dataparticipantsinfoformat1.h"

namespace pcars {


Data_Participants_Info_Format_1::Data_Participants_Info_Format_1(Decoder_Telemetry_Data * telemetry_data) 
	: telemetry_data_{telemetry_data} {}

Vector_Int Data_Participants_Info_Format_1::world_position(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).world_position();
}

Vector_Int Data_Participants_Info_Format_1::orientation(const Participant) const {
	Vector_Int vec;
	return vec;
}

unsigned int Data_Participants_Info_Format_1::current_lap_distance(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).current_lap_distance();
}

unsigned int Data_Participants_Info_Format_1::race_position(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).race_position();
}

bool Data_Participants_Info_Format_1::is_active(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).is_active();
}

unsigned int Data_Participants_Info_Format_1::world_positionZ(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).world_positionZ();
}

unsigned int Data_Participants_Info_Format_1::world_positionX(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).world_positionX();
}

unsigned int Data_Participants_Info_Format_1::sector(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).sector();
}

unsigned int Data_Participants_Info_Format_1::flag_colour(const Participant) const {
	return 0;
}

unsigned int Data_Participants_Info_Format_1::flag_reason(const Participant) const {
	return 0;
}

unsigned int Data_Participants_Info_Format_1::pit_mode(const Participant) const {
	return 0;
}

unsigned int Data_Participants_Info_Format_1::pit_schedule(const Participant) const {
	return 0;
}

bool Data_Participants_Info_Format_1::local_player(const Participant) const {
	return 0;
}

bool Data_Participants_Info_Format_1::remote_player(const Participant) const {
	return 0;
}

bool Data_Participants_Info_Format_1::human_player(const Participant) const {
	return 0;
}

bool Data_Participants_Info_Format_1::none_human_player(const Participant) const {
	return 0;
}

unsigned int Data_Participants_Info_Format_1::car_index(const Participant) const {
	return 0;
}

bool Data_Participants_Info_Format_1::lap_invalidated(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).lap_invalidated();
}

unsigned int Data_Participants_Info_Format_1::race_state(const Participant) const {
	return 0;
}

unsigned int Data_Participants_Info_Format_1::current_lap(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).current_lap();
}

float Data_Participants_Info_Format_1::current_time(const Participant) const {
	return 0;
}

float Data_Participants_Info_Format_1::current_sector_time(const Participant) const {
	return 0;
}

unsigned int Data_Participants_Info_Format_1::laps_completed(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).laps_completed();
}

bool Data_Participants_Info_Format_1::same_class(const Participant participant) const {
	return telemetry_data_->participant_info().at(participant).same_class();
}

unsigned int Data_Participants_Info_Format_1::participant_index() const {
	return telemetry_data_->viewed_participant_index();
}

Data_Participants_Info_Format_1:: Participants Data_Participants_Info_Format_1::participants() const {
	return telemetry_data_->num_participants();
}

}

