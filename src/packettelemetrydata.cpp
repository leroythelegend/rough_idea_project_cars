#include "packettelemetrydata.h"

namespace pcars {

Packet_Telemetry_Data::Packet_Telemetry_Data() {
	add(&packet_base_);
	add(&viewed_participant_index_);
	add(&unfiltered_throttle_);
	add(&unfiltered_brake_);
	add(&unfiltered_steering_);
	add(&unfiltered_clutch_);
	add(&car_flags_);	
	add(&oil_temp_celsius_);
	add(&oil_pressure_kpa_);
	add(&water_temp_celsius_);
	add(&water_pressure_kpa_);
	add(&fuel_pressure_kpa_);
	add(&fuel_capacity_);
	add(&brake_);
	add(&throttle_);
	add(&clutch_);
	add(&fuel_level_);
	add(&speed_);
	add(&rpm_);
	add(&max_rpm_);
	add(&steering_);
	add(&gear_num_gears_);
	add(&boost_amount_);
	add(&crash_state_);
	add(&odometer_km_);
	add(&orientation_);
	add(&local_velocity_);
	add(&world_velocity_);
	add(&angular_velocity_);
	add(&local_acceleration_);
	add(&world_acceleration_);
	add(&extents_centre_);
	add(&tyre_flags_);
	add(&terrain_);
	add(&tyre_y_);
	add(&tyre_rps_);
	add(&tyre_temp_);
	add(&tyre_height_above_ground_);
	add(&tyre_wear_);
	add(&brake_damage_);
	add(&suspension_damage_);
	add(&brake_temp_celsius_);
	add(&tyre_tread_temp_);
	add(&tyre_layer_temp_);
	add(&tyre_carcass_temp_);
	add(&tyre_rim_temp_);
	add(&tyre_internal_air_temp_);
	add(&tyre_temp_left_);
	add(&tyre_temp_center_);
	add(&tyre_temp_right_);	
	add(&wheel_local_position_y_);
	add(&ride_height_);
	add(&suspension_travel_);
	add(&suspension_velocity_);
	add(&suspension_ride_height_);
	add(&air_pressure_);
	add(&engine_speed_);
	add(&engine_torque_);
	add(&wings_);
	add(&handbrake_);
	add(&aero_damage_);
	add(&engine_damage_);
	add(&joy_pad_0_);
	add(&d_pad_);
	add(&tyre_compound_);
	add(&turbo_boost_pressure_);
	add(&full_position_);
	add(&brake_bias_);
	add(&tick_count_);
}

Packet_Base Packet_Telemetry_Data::packet_base() const {
	return packet_base_;
}

int Packet_Telemetry_Data::viewed_participant_index() const {
	return viewed_participant_index_.s8();
}

unsigned int Packet_Telemetry_Data::unfiltered_throttle() const {
	return unfiltered_throttle_.u8();
}

unsigned int Packet_Telemetry_Data::unfiltered_brake() const {
	return unfiltered_brake_.u8();
}

int Packet_Telemetry_Data::unfiltered_steering() const {
	return unfiltered_steering_.s8();
}

unsigned int Packet_Telemetry_Data::unfiltered_clutch() const {
	return unfiltered_clutch_.u8();
}

unsigned int Packet_Telemetry_Data::car_flags() const {
	return car_flags_.u8();
}

int Packet_Telemetry_Data::oil_temp_celsius() const {
	return oil_temp_celsius_.s16();
}

unsigned int Packet_Telemetry_Data::oil_pressure_kpa() const {
	return oil_pressure_kpa_.u16();
}

int Packet_Telemetry_Data::water_temp_celsius() const {
	return water_temp_celsius_.s16();
}

unsigned int Packet_Telemetry_Data::water_pressure_kpa() const {
	return water_pressure_kpa_.u16();
}

unsigned int Packet_Telemetry_Data::fuel_pressure_kpa() const {
	return fuel_pressure_kpa_.u16();
}

unsigned int Packet_Telemetry_Data::fuel_capacity() const {
	return fuel_capacity_.u8();
}

unsigned int Packet_Telemetry_Data::brake() const {
	return brake_.u8();
}

unsigned int Packet_Telemetry_Data::throttle() const {
	return throttle_.u8();
}

unsigned int Packet_Telemetry_Data::clutch() const {
	return clutch_.u8();
}

float Packet_Telemetry_Data::fuel_level() const {
	return fuel_level_.f32();
}

float Packet_Telemetry_Data::speed() const {
	return speed_.f32();
}

unsigned int Packet_Telemetry_Data::rpm() const {
	return rpm_.u16();
}

unsigned int Packet_Telemetry_Data::max_rpm() const {
	return max_rpm_.u16();
}

int Packet_Telemetry_Data::steering() const {
	return steering_.s8();
}

unsigned int Packet_Telemetry_Data::gears() const {
	return gear_num_gears_.ms4bits();
}

unsigned int Packet_Telemetry_Data::gear() const {
	return gear_num_gears_.ls4bits();
}

unsigned int Packet_Telemetry_Data::boost_amount() const {
	return boost_amount_.u8();
}

unsigned int Packet_Telemetry_Data::crash_state() const {
	return crash_state_.u8();
}

float Packet_Telemetry_Data::odometer_km() const {
	return odometer_km_.f32();
}

Vector_Float Packet_Telemetry_Data::orientation() const {
	return orientation_.times3_float();
}

Vector_Float Packet_Telemetry_Data::local_velocity() const {
	return local_velocity_.times3_float();
}

Vector_Float Packet_Telemetry_Data::world_velocity() const {
	return world_velocity_.times3_float();
}

Vector_Float Packet_Telemetry_Data::angular_velocity() const {
	return angular_velocity_.times3_float();
}

Vector_Float Packet_Telemetry_Data::local_acceleration() const {
	return local_acceleration_.times3_float();
}

Vector_Float Packet_Telemetry_Data::world_acceleration() const {
	return world_acceleration_.times3_float();
}

Vector_Float Packet_Telemetry_Data::extents_centre() const {
	return extents_centre_.times3_float();
}

Vector_UInt Packet_Telemetry_Data::tyre_flags() const {
	return tyre_flags_.times4_u8();
}

Vector_UInt Packet_Telemetry_Data::terrain() const {
	return terrain_.times4_u8();
}

Vector_Float Packet_Telemetry_Data::tyre_y() const {
	return tyre_y_.times4_float();
}

Vector_Float Packet_Telemetry_Data::tyre_rps() const {
	return tyre_rps_.times4_float();
}

Vector_UInt Packet_Telemetry_Data::tyre_temp() const {
	return tyre_temp_.times4_u8();
}
Vector_Float Packet_Telemetry_Data::tyre_height_above_ground() const {
	return tyre_height_above_ground_.times4_float();
}

Vector_UInt Packet_Telemetry_Data::tyre_wear() const {
	return tyre_wear_.times4_u8();
}

Vector_UInt Packet_Telemetry_Data::brake_damage() const {
	return brake_damage_.times4_u8();
}

Vector_UInt Packet_Telemetry_Data::suspension_damage() const {
	return suspension_damage_.times4_u8();
}

Vector_Int Packet_Telemetry_Data::brake_temp_celsius() const {
	return brake_temp_celsius_.times4_s16();
}

Vector_UInt Packet_Telemetry_Data::tyre_tread_temp() const {
	return tyre_tread_temp_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::tyre_layer_temp() const {
	return tyre_layer_temp_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::tyre_carcass_temp() const {
	return tyre_carcass_temp_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::tyre_rim_temp() const {
	return tyre_rim_temp_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::tyre_internal_air_temp() const {
	return tyre_internal_air_temp_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::tyre_temp_left() const {
	return tyre_temp_left_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::tyre_temp_center() const {
	return tyre_temp_center_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::tyre_temp_right() const {
	return tyre_temp_right_.times4_u16();
}

Vector_Float Packet_Telemetry_Data::wheel_local_position_y() const {
	return wheel_local_position_y_.times4_float();
}

Vector_Float Packet_Telemetry_Data::ride_height() const {
	return ride_height_.times4_float();
}

Vector_Float Packet_Telemetry_Data::suspension_travel() const {
	return suspension_travel_.times4_float();
}

Vector_Float Packet_Telemetry_Data::suspension_velocity() const {
	return suspension_velocity_.times4_float();
}

Vector_UInt Packet_Telemetry_Data::suspension_ride_height() const {
	return suspension_ride_height_.times4_u16();
}

Vector_UInt Packet_Telemetry_Data::air_pressure() const {
	return air_pressure_.times4_u16();
}

float Packet_Telemetry_Data::engine_speed() const {
	return engine_speed_.f32();
}

float Packet_Telemetry_Data::engine_torque() const {
	return engine_torque_.f32();
}

Vector_UInt Packet_Telemetry_Data::wings() const {
	return wings_.times2_U8();
}

unsigned int Packet_Telemetry_Data::handbrake() const {
	return handbrake_.u8();
}

unsigned int Packet_Telemetry_Data::aero_damage() const {
	return aero_damage_.u8();
}

unsigned int Packet_Telemetry_Data::engine_damage() const {
	return engine_damage_.u8();
}

unsigned int Packet_Telemetry_Data::joy_pad_0() const {
	return joy_pad_0_.u32();
}

unsigned int Packet_Telemetry_Data::d_pad() const {
	return d_pad_.u8();
}

Vector_String Packet_Telemetry_Data::tyre_compound() const {
	return tyre_compound_.times4_40Char();
}

float Packet_Telemetry_Data::turbo_boost_pressure() const {
	return turbo_boost_pressure_.f32();
}

Vector_Float Packet_Telemetry_Data::full_position() const {
	return full_position_.times3_float();
}

unsigned int Packet_Telemetry_Data::brake_bias() const {
	return brake_bias_.u8();
}

unsigned int Packet_Telemetry_Data::tick_count() const {
	return tick_count_.u32();
}

}
