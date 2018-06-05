#include "datacarstateformat2.h"

namespace pcars {

Data_Car_State_Format_2::Data_Car_State_Format_2(const Packet& packet)
	: packet_{packet} {}

unsigned int Data_Car_State_Format_2::car_flags() const {
	return packet_.telemetry_data().car_flags();
}

int Data_Car_State_Format_2::oil_temp_celsius() const {
	return packet_.telemetry_data().oil_temp_celsius();
}

unsigned int Data_Car_State_Format_2::oil_pressure_kpa() const {
	return packet_.telemetry_data().oil_pressure_kpa();
}

int Data_Car_State_Format_2::water_temp_celsius() const {
	return packet_.telemetry_data().water_temp_celsius();
}

unsigned int Data_Car_State_Format_2::water_pressure_kpa() const {
	return packet_.telemetry_data().water_pressure_kpa();
}

unsigned int Data_Car_State_Format_2::fuel_pressure_kpa() const {
	return packet_.telemetry_data().fuel_pressure_kpa();
}

unsigned int Data_Car_State_Format_2::fuel_capacity() const {
	return packet_.telemetry_data().fuel_capacity();
}

unsigned int Data_Car_State_Format_2::brake() const {
	return packet_.telemetry_data().brake();
}

unsigned int Data_Car_State_Format_2::throttle() const {
	return packet_.telemetry_data().throttle();
}

unsigned int Data_Car_State_Format_2::clutch() const {
	return packet_.telemetry_data().clutch();
}

float Data_Car_State_Format_2::fuel_level() const {
	return packet_.telemetry_data().fuel_level();
}

float Data_Car_State_Format_2::speed() const {
	return packet_.telemetry_data().speed();
}

unsigned int Data_Car_State_Format_2::rpm() const {
	return packet_.telemetry_data().rpm();
}

unsigned int Data_Car_State_Format_2::max_rpm() const {
	return packet_.telemetry_data().max_rpm();
}

int Data_Car_State_Format_2::steering() const {
	return packet_.telemetry_data().steering();
}

unsigned int Data_Car_State_Format_2::gears() const {
	return packet_.telemetry_data().gears();
}

unsigned int Data_Car_State_Format_2::gear() const {
	return packet_.telemetry_data().gear();
}

unsigned int Data_Car_State_Format_2::boost_amount() const {
	return packet_.telemetry_data().boost_amount();
}

unsigned int Data_Car_State_Format_2::crash_state() const {
	return packet_.telemetry_data().crash_state();
}

float Data_Car_State_Format_2::odometer_km() const {
	return packet_.telemetry_data().odometer_km();
}

Vector_UInt Data_Car_State_Format_2::tyre_flags() const {
	return packet_.telemetry_data().tyre_flags();
}

Vector_UInt Data_Car_State_Format_2::terrain() const {
	return packet_.telemetry_data().terrain();
}

Vector_Float Data_Car_State_Format_2::tyre_y() const {
	return packet_.telemetry_data().tyre_y();
}

Vector_Float Data_Car_State_Format_2::tyre_rps() const {
	return packet_.telemetry_data().tyre_rps();
}

Vector_Float Data_Car_State_Format_2::tyre_slip_speed() const {
	Vector_Float vec;
	return vec;
}

Vector_UInt Data_Car_State_Format_2::tyre_grip() const {
	Vector_UInt vec;
	return vec;
}

Vector_UInt Data_Car_State_Format_2::tyre_temp() const {
	return packet_.telemetry_data().tyre_temp();
}

Vector_Float Data_Car_State_Format_2::tyre_lateral_stiffness() const {
	Vector_Float vec;
	return vec;
}

Vector_Float Data_Car_State_Format_2::tyre_height_above_ground() const {
	return packet_.telemetry_data().tyre_height_above_ground();
}

Vector_UInt Data_Car_State_Format_2::tyre_wear() const {
	return packet_.telemetry_data().tyre_wear();
}

Vector_Int Data_Car_State_Format_2::brake_temp_celsius() const {
	return packet_.telemetry_data().brake_temp_celsius(); 
}

Vector_UInt Data_Car_State_Format_2::tyre_tread_temp() const {
	return packet_.telemetry_data().tyre_tread_temp();
}

Vector_UInt Data_Car_State_Format_2::tyre_layer_temp() const {
	return packet_.telemetry_data().tyre_layer_temp();
}

Vector_UInt Data_Car_State_Format_2::tyre_carcass_temp() const {
	return packet_.telemetry_data().tyre_carcass_temp();
}

Vector_UInt Data_Car_State_Format_2::tyre_rim_temp() const {
	return packet_.telemetry_data().tyre_rim_temp();
}

Vector_UInt Data_Car_State_Format_2::tyre_internal_air_temp() const {
	return packet_.telemetry_data().tyre_internal_air_temp();
}

Vector_UInt Data_Car_State_Format_2::tyre_temp_left() const {
	return packet_.telemetry_data().tyre_temp_left(); 
}

Vector_UInt Data_Car_State_Format_2::tyre_temp_center() const {
	return packet_.telemetry_data().tyre_temp_center();
}

Vector_UInt Data_Car_State_Format_2::tyre_temp_right() const {
	return packet_.telemetry_data().tyre_temp_right();
}

Vector_Float Data_Car_State_Format_2::wheel_local_position_y() const {
	return packet_.telemetry_data().wheel_local_position_y();
}

Vector_Float Data_Car_State_Format_2::ride_height() const {
	return packet_.telemetry_data().ride_height();
}

Vector_Float Data_Car_State_Format_2::suspension_travel() const {
	return packet_.telemetry_data().suspension_travel();
}

Vector_Float Data_Car_State_Format_2::suspension_velocity() const {
	return packet_.telemetry_data().suspension_velocity();
}

Vector_UInt Data_Car_State_Format_2::suspension_ride_height() const {
	return packet_.telemetry_data().suspension_ride_height();
}

Vector_UInt Data_Car_State_Format_2::air_pressure() const {
	return packet_.telemetry_data().air_pressure();
}

float Data_Car_State_Format_2::engine_speed() const {
	return packet_.telemetry_data().engine_speed();
}

float Data_Car_State_Format_2::engine_torque() const {
	return packet_.telemetry_data().engine_torque();
}

Vector_UInt Data_Car_State_Format_2::wings() const {
	return packet_.telemetry_data().wings();
}

unsigned int Data_Car_State_Format_2::handbrake() const {
	return packet_.telemetry_data().handbrake();
}

Vector_String Data_Car_State_Format_2::tyre_compound() const {
	return packet_.telemetry_data().tyre_compound();
}

float Data_Car_State_Format_2::turbo_boost_pressure() const {
	return packet_.telemetry_data().turbo_boost_pressure();
}

unsigned int Data_Car_State_Format_2::brake_bias() const {
	return packet_.telemetry_data().brake_bias(); 
}

Vector_Float Data_Car_State_Format_2::full_position() const {
	return packet_.telemetry_data().full_position(); 
}

unsigned int Data_Car_State_Format_2::tick_count() const {
	return packet_.telemetry_data().tick_count();
}

};

