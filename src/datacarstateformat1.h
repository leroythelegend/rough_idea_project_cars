#ifndef PCARS_DATA_CAR_STATE_FORMAT_1_H_
#define PCARS_DATA_CAR_STATE_FORMAT_1_H_

#include "consts.h"
#include "datacarstate.h"
#include "decodertelemetrydata.h"

namespace pcars {

class Data_Car_State_Format_1 : public Data_Car_State {
public:
	Data_Car_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
	virtual ~Data_Car_State_Format_1() {}

	unsigned int car_flags() const override;	
	int oil_temp_celsius() const override;
	unsigned int oil_pressure_kpa() const override;
	int water_temp_celsius() const override;
	unsigned int water_pressure_kpa() const override;
	unsigned int fuel_pressure_kpa() const override;
	unsigned int fuel_capacity() const override;
	unsigned int brake() const override;
	unsigned int throttle() const override;
	unsigned int clutch() const override;
	float fuel_level() const override;
	float speed() const override;
	unsigned int rpm() const override;
	unsigned int max_rpm() const override;
	int steering() const override;
	unsigned int gears() const override;
	unsigned int gear() const override;
	unsigned int boost_amount() const override;
	unsigned int crash_state() const override;
	float odometer_km() const override;
	Vector_UInt tyre_flags() const override;
	Vector_UInt terrain() const override;
	Vector_Float tyre_y() const override;
	Vector_Float tyre_rps() const override;
	Vector_Float tyre_slip_speed() const override;
	Vector_UInt tyre_grip() const override;
	Vector_UInt tyre_temp() const override;
	Vector_Float tyre_lateral_stiffness() const override;
	Vector_Float tyre_height_above_ground() const override;
	Vector_UInt tyre_wear() const override;
	Vector_Int brake_temp_celsius() const override;
	Vector_UInt tyre_tread_temp() const override;
	Vector_UInt tyre_layer_temp() const override;
	Vector_UInt tyre_carcass_temp() const override;
	Vector_UInt tyre_rim_temp() const override;
	Vector_UInt tyre_internal_air_temp() const override;
	Vector_UInt tyre_temp_left() const override;
	Vector_UInt tyre_temp_center() const override;
	Vector_UInt tyre_temp_right() const override;	
	Vector_Float wheel_local_position_y() const override;
	Vector_Float ride_height() const override;
	Vector_Float suspension_travel() const override;
	Vector_Float suspension_velocity() const override;
	Vector_UInt suspension_ride_height() const override;
	Vector_UInt air_pressure() const override;
	float engine_speed() const override;
	float engine_torque() const override;
	Vector_UInt wings() const override;
	unsigned int handbrake() const override;
	Vector_String tyre_compound() const override;
	float turbo_boost_pressure() const override;
	unsigned int brake_bias() const override;
	Vector_Float full_position() const override;

private:
	std::shared_ptr<Decoder_Telemetry_Data> telemetry_data_;
};

}

#endif

