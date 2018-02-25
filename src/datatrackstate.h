#ifndef PCARS_DATA_TRACK_STATE_H_
#define PCARS_DATA_TRACK_STATE_H_

#include "consts.h"

namespace pcars {

class Data_Track_State {
public:
	virtual ~Data_Track_State() {}

	virtual	float world_fastest_lap_time() const = 0;
	virtual	float personal_fastest_lap_time() const = 0;	
	virtual	float personal_fastest_sector1_time() const = 0;
	virtual	float personal_fastest_sector2_time() const = 0;
	virtual	float personal_fastest_sector3_time() const = 0;
	virtual	float world_fastest_sector1_time() const = 0;
	virtual	float world_fastest_sector2_time() const = 0;
	virtual	float world_fastest_sector3_time() const = 0;
	virtual	float track_length() const = 0;
	virtual	std::string track_location() const = 0;	
	virtual	std::string track_variation() const = 0;	
	virtual	std::string translated_track_location() const = 0;
	virtual	std::string translated_track_variation() const = 0;
	virtual	unsigned int laps_time_in_event() const = 0;
	virtual	int enforced_pitstop_lap() const = 0;
	virtual int ambient_temp() const = 0;
	virtual int track_temp() const = 0;
	virtual unsigned int rain_density() const = 0;
	virtual unsigned int snow_density() const = 0;
	virtual int wind_speed() const = 0;
	virtual int wind_direction_x() const = 0;
	virtual int wind_direction_y() const = 0;
};

}

#endif

