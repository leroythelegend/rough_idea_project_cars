#ifndef PCARS_DATA_TRACK_STATE_FORMAT_2_H_
#define PCARS_DATA_TRACK_STATE_FORMAT_2_H_

#include "datatrackstate.h"
#include "packet.h"

namespace pcars {

class Data_Track_State_Format_2 : public Data_Track_State {
public:
	Data_Track_State_Format_2(const Packet&);
	virtual ~Data_Track_State_Format_2() {}

	float world_fastest_lap_time() const override;
	float personal_fastest_lap_time() const override;	
	float personal_fastest_sector1_time() const override;
	float personal_fastest_sector2_time() const override;
	float personal_fastest_sector3_time() const override;
	float world_fastest_sector1_time() const override;
	float world_fastest_sector2_time() const override;
	float world_fastest_sector3_time() const override;
	float track_length() const override;
	std::string track_location() const override;	
	std::string track_variation() const override;	
	std::string translated_track_location() const override;
	std::string translated_track_variation() const override;
	unsigned int laps_time_in_event() const override;
	int enforced_pitstop_lap() const override;
	int ambient_temp() const override;
	int track_temp() const override;
	unsigned int rain_density() const override;
	unsigned int snow_density() const override;
	int wind_speed() const override;
	int wind_direction_x() const override;
	int wind_direction_y() const override;

private:
	Packet packet_; 

};

}

#endif

