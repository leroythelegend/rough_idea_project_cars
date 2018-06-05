#ifndef PCARS_DATA_CAR_STATE_H_
#define PCARS_DATA_CAR_STATE_H_

#include "consts.h"

namespace pcars {

class Data_Car_State {
public:
	virtual ~Data_Car_State() {}

	virtual	unsigned int car_flags() const = 0;	
	virtual	int oil_temp_celsius() const = 0;
	virtual	unsigned int oil_pressure_kpa() const = 0;
	virtual	int water_temp_celsius() const = 0;
	virtual	unsigned int water_pressure_kpa() const = 0;
	virtual	unsigned int fuel_pressure_kpa() const = 0;
	virtual	unsigned int fuel_capacity() const = 0;
	virtual	unsigned int brake() const = 0;
	virtual	unsigned int throttle() const = 0;
	virtual	unsigned int clutch() const = 0;
	virtual	float fuel_level() const = 0;
	virtual	float speed() const = 0;
	virtual	unsigned int rpm() const = 0;
	virtual	unsigned int max_rpm() const = 0;
	virtual	int steering() const = 0;
	virtual	unsigned int gears() const = 0;
	virtual	unsigned int gear() const = 0;
	virtual	unsigned int boost_amount() const = 0;
	virtual	unsigned int crash_state() const = 0;
	virtual	float odometer_km() const = 0;
	virtual	Vector_UInt tyre_flags() const = 0;
	virtual	Vector_UInt terrain() const = 0;
	virtual	Vector_Float tyre_y() const = 0;
	virtual	Vector_Float tyre_rps() const = 0;
	virtual Vector_Float tyre_slip_speed() const = 0;
	virtual Vector_UInt tyre_grip() const = 0;
	virtual	Vector_UInt tyre_temp() const = 0;
	virtual Vector_Float tyre_lateral_stiffness() const = 0;
	virtual	Vector_Float tyre_height_above_ground() const = 0;
	virtual	Vector_UInt tyre_wear() const = 0;
	virtual	Vector_Int brake_temp_celsius() const = 0;
	virtual	Vector_UInt tyre_tread_temp() const = 0;
	virtual	Vector_UInt tyre_layer_temp() const = 0;
	virtual	Vector_UInt tyre_carcass_temp() const = 0;
	virtual	Vector_UInt tyre_rim_temp() const = 0;
	virtual	Vector_UInt tyre_internal_air_temp() const = 0;
	virtual	Vector_UInt tyre_temp_left() const = 0;
	virtual	Vector_UInt tyre_temp_center() const = 0;
	virtual	Vector_UInt tyre_temp_right() const = 0;	
	virtual	Vector_Float wheel_local_position_y() const = 0;
	virtual	Vector_Float ride_height() const = 0;
	virtual	Vector_Float suspension_travel() const = 0;
	virtual	Vector_Float suspension_velocity() const = 0;
	virtual	Vector_UInt suspension_ride_height() const = 0;
	virtual	Vector_UInt air_pressure() const = 0;
	virtual	float engine_speed() const = 0;
	virtual	float engine_torque() const = 0;
	virtual	Vector_UInt wings() const = 0;
	virtual	unsigned int handbrake() const = 0;
	virtual	Vector_String tyre_compound() const = 0;
	virtual	float turbo_boost_pressure() const = 0;
	virtual	unsigned int brake_bias() const = 0;
	virtual	Vector_Float full_position() const = 0;
	virtual unsigned int tick_count() const = 0;
};

}

#endif

