#ifndef PCARS_DATA_PARTICIPANTS_INFO_H_
#define PCARS_DATA_PARTICIPANTS_INFO_H_

#include "consts.h"

namespace pcars {

class Data_Participants_Info {
public:
	using Participant = unsigned int;
	using Participants = unsigned int;

	virtual ~Data_Participants_Info() {}

	virtual	Vector_Int world_position(const Participant) const = 0;
	virtual	Vector_Int orientation(const Participant) const = 0;
	virtual unsigned int current_lap_distance(const Participant) const = 0;
	virtual unsigned int race_position(const Participant) const = 0;
	virtual bool is_active(const Participant) const = 0;
	virtual unsigned int world_positionZ(const Participant) const = 0;
	virtual unsigned int world_positionX(const Participant) const = 0;
	virtual unsigned int sector(const Participant) const = 0;
	virtual unsigned int flag_colour(const Participant) const = 0;
	virtual unsigned int flag_reason(const Participant) const = 0;
	virtual unsigned int pit_mode(const Participant) const = 0;
	virtual unsigned int pit_schedule(const Participant) const = 0;
	virtual bool local_player(const Participant) const = 0;
	virtual bool remote_player(const Participant) const = 0;
	virtual bool human_player(const Participant) const = 0;
	virtual bool none_human_player(const Participant) const = 0;
	virtual unsigned int car_index(const Participant) const = 0;
	virtual bool lap_invalidated(const Participant) const = 0;
	virtual unsigned int race_state(const Participant) const = 0;
	virtual unsigned int current_lap(const Participant) const = 0;
	virtual float current_time(const Participant) const = 0;
	virtual float current_sector_time(const Participant) const = 0;
	virtual unsigned int laps_completed(const Participant) const = 0;
	virtual bool same_class(const Participant) const = 0;

	virtual unsigned int participant_index() const = 0;
	virtual Participants participants() const = 0;
};

}

#endif

