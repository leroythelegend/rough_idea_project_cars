#ifndef PCARS_DATA_PARTICIPANTS_STATS_FORMAT_1_H_
#define PCARS_DATA_PARTICIPANTS_STATS_FORMAT_1_H_

#include "dataparticipantsstats.h"

namespace pcars {

class Data_Participants_Stats_Format_1 : public Data_Participants_Stats {
public:
	using Participant = unsigned int;
	using Participants = unsigned int;

	Data_Participants_Stats_Format_1();
	virtual ~Data_Participants_Stats_Format_1() {}

	float fastest_lap_time(const Participant) const override;
	float last_lap_time(const Participant) const override;
	float last_sector_time(const Participant) const override;
	float fastest_sector_1_time(const Participant) const override;
	float fastest_sector_2_time(const Participant) const override;
	float fastest_sector_3_time(const Participant) const override;
	unsigned int participants_online_rank(const Participant) const override;
	unsigned int participants_online_strength(const Participant) const override;

	unsigned int participant_index() const override;
	Participants participants() const override;

};

}

#endif

