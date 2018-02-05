#ifndef PCARS_PACKET_H_
#define PCARS_PACKET_H_

#include "decoder.h"

#include "packetgamestate.h"
#include "packettelemetrydata.h"
#include "packettimingdata.h"
#include "packetracedata.h"
#include "packetparticipantsdata.h"
#include "packettimestatsdata.h"
#include "packetparticipantvehiclenamesdata.h"

namespace pcars {

class Packet : public Decoder {
public:
	virtual ~Packet() {}

	void decode(const PCars_Data &, Position &) override;

	const Packet_Game_State& game_state() const;
	const Packet_Telemetry_Data& telemetry_data() const;
	const Packet_Timing_Data& timing_data() const;
	const Packet_Race_Data& race_data() const;
	const Packet_Participants_Data& participants_data() const;
	const Packet_Participants_Data& participants_data_2() const;
	const Packet_Time_Stats_Data& time_stats_data() const;
	const Packet_Participants_Vehicle_Names_Data& vehicle_names() const;
	const Packet_Participants_Vehicle_Names_Data& vehicle_names_2() const;

private:
	Packet_Game_State game_state_;
	Packet_Telemetry_Data telemetry_data_;
	Packet_Timing_Data timing_data_;
	Packet_Race_Data race_data_;
	Packet_Participants_Data participants_data_;
	Packet_Participants_Data participants_data_2_;
	Packet_Time_Stats_Data time_stats_data_;
	Packet_Participants_Vehicle_Names_Data vehicle_names_;
	Packet_Participants_Vehicle_Names_Data vehicle_names_2_;
};

}

#endif

