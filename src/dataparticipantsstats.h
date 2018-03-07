#ifndef PCARS_DATA_PARTICIPANTS_STATS_H_
#define PCARS_DATA_PARTICIPANTS_STATS_H_

#include "consts.h"

namespace pcars {

class Data_Participants_Stats {
public:
	using Participant = unsigned int;
	using Participants = unsigned int;

	virtual ~Data_Participants_Stats() {}

	virtual	float fastest_lap_time(const Participant) const = 0;
	virtual	float last_lap_time(const Participant) const = 0;
	virtual	float last_sector_time(const Participant) const = 0;
	virtual	float fastest_sector_1_time(const Participant) const = 0;
	virtual	float fastest_sector_2_time(const Participant) const = 0;
	virtual	float fastest_sector_3_time(const Participant) const = 0;
	virtual unsigned int participants_online_rank(const Participant) const = 0;
	virtual unsigned int participants_online_strength(const Participant) const = 0;


	virtual unsigned int participant_index() const = 0;
	virtual Participants participants() const = 0;
};

}

#endif

