#ifndef PCARS_DATA_PARTICIPANTS_INFO_FORMAT_1_H_
#define PCARS_DATA_PARTICIPANTS_INFO_FORMAT_1_H_

#include "dataparticipantsinfo.h"
#include "decodertelemetrydata.h"

#include <memory>

namespace pcars {

class Data_Participants_Info_Format_1 : public Data_Participants_Info {
public:
	using Participant = unsigned int;
	using Participants = unsigned int;

	Data_Participants_Info_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
	virtual ~Data_Participants_Info_Format_1() {}

	Vector_Int world_position(const Participant) const override;
	Vector_Int orientation(const Participant) const override;
	unsigned int current_lap_distance(const Participant) const override;
	unsigned int race_position(const Participant) const override;
	bool is_active(const Participant) const override;
	unsigned int world_positionZ(const Participant) const override;
	unsigned int world_positionX(const Participant) const override;
	unsigned int sector(const Participant) const override;
	unsigned int flag_colour(const Participant) const override;
	unsigned int flag_reason(const Participant) const override;
	unsigned int pit_mode(const Participant) const override;
	unsigned int pit_schedule(const Participant) const override;
	bool local_player(const Participant) const override;
	bool remote_player(const Participant) const override;
	bool human_player(const Participant) const override;
	bool none_human_player(const Participant) const override;
	unsigned int car_index(const Participant) const override;
	bool lap_invalidated(const Participant) const override;
	unsigned int race_state(const Participant) const override;
	unsigned int current_lap(const Participant) const override;
	float current_time(const Participant) const override;
	float current_sector_time(const Participant) const override;
	unsigned int laps_completed(const Participant) const override;
	bool same_class(const Participant) const override;

	unsigned int participant_index() const override;
	Participants participants() const override;

private:
	std::shared_ptr<Decoder_Telemetry_Data> telemetry_data_;
};

}

#endif

