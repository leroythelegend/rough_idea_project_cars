#include "datacarstateformat1.h"

namespace pcars {

Data_Car_State_Format_1::Data_Car_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data> telemetry_data)
	: telemetry_data_{telemetry_data} {}

unsigned int Data_Car_State_Format_1::car_flags() const {
	return telemetry_data_->car_flags();
}

int Data_Car_State_Format_1::oil_temp_celsius() const {
	return telemetry_data_->oil_temp_celsius();
}

unsigned int Data_Car_State_Format_1::oil_pressure_kpa() const {
	return telemetry_data_->oil_pressure_kpa();
}

int Data_Car_State_Format_1::water_temp_celsius() const {
	return telemetry_data_->water_temp_celsius();
}

unsigned int Data_Car_State_Format_1::water_pressure_kpa() const {
	return telemetry_data_->water_pressure_kpa();
}

unsigned int Data_Car_State_Format_1::fuel_pressure_kpa() const {
	return telemetry_data_->fuel_pressure_kpa();
}

unsigned int Data_Car_State_Format_1::fuel_capacity() const {
	return telemetry_data_->fuel_capacity();
}

unsigned int Data_Car_State_Format_1::brake() const {
	return telemetry_data_->brake();
}

unsigned int Data_Car_State_Format_1::throttle() const {
	return telemetry_data_->throttle();
}

unsigned int Data_Car_State_Format_1::clutch() const {
	return telemetry_data_->clutch();
}

float Data_Car_State_Format_1::fuel_level() const {
	return telemetry_data_->fuel_level();
}

float Data_Car_State_Format_1::speed() const {
	return telemetry_data_->speed();
}

unsigned int Data_Car_State_Format_1::rpm() const {
	return telemetry_data_->rpm();
}

unsigned int Data_Car_State_Format_1::max_rpm() const {
	return telemetry_data_->max_rpm();
}

int Data_Car_State_Format_1::steering() const {
	return telemetry_data_->steering();
}

unsigned int Data_Car_State_Format_1::gears() const {
	return telemetry_data_->num_gears();
}

unsigned int Data_Car_State_Format_1::gear() const {
	return telemetry_data_->gear();
}

unsigned int Data_Car_State_Format_1::boost_amount() const {
	return telemetry_data_->boost_amount();
}

unsigned int Data_Car_State_Format_1::crash_state() const {
	return telemetry_data_->crash_state();
}

float Data_Car_State_Format_1::odometer_km() const {
	return telemetry_data_->odometer_km();
}

Vector_UInt Data_Car_State_Format_1::tyre_flags() const {
	return telemetry_data_->tyre_flags();
}

Vector_UInt Data_Car_State_Format_1::terrain() const {
	return telemetry_data_->terrain();
}

Vector_Float Data_Car_State_Format_1::tyre_y() const {
	return telemetry_data_->tyre_y();
}

Vector_Float Data_Car_State_Format_1::tyre_rps() const {
	return telemetry_data_->tyre_rps();
}

Vector_Float Data_Car_State_Format_1::tyre_slip_speed() const {
	return telemetry_data_->tyre_slip_speed();
}

Vector_UInt Data_Car_State_Format_1::tyre_grip() const {
	return telemetry_data_->tyre_grip();
}

Vector_UInt Data_Car_State_Format_1::tyre_temp() const {
	return telemetry_data_->tyre_temp();
}

Vector_Float Data_Car_State_Format_1::tyre_lateral_stiffness() const {
	return telemetry_data_->tyre_lateral_stiffness();
}

Vector_Float Data_Car_State_Format_1::tyre_height_above_ground() const {
	return telemetry_data_->tyre_height_above_ground();
}

Vector_UInt Data_Car_State_Format_1::tyre_wear() const {
	return telemetry_data_->tyre_wear();
}

Vector_Int Data_Car_State_Format_1::brake_temp_celsius() const {
	return telemetry_data_->brake_temp_celsius();
}

Vector_UInt Data_Car_State_Format_1::tyre_tread_temp() const {
	return telemetry_data_->tyre_tread_temp();
}

Vector_UInt Data_Car_State_Format_1::tyre_layer_temp() const {
	return telemetry_data_->tyre_layer_temp();
}

Vector_UInt Data_Car_State_Format_1::tyre_carcass_temp() const {
	return telemetry_data_->tyre_carcass_temp();
}

Vector_UInt Data_Car_State_Format_1::tyre_rim_temp() const {
	return telemetry_data_->tyre_rim_temp();
}

Vector_UInt Data_Car_State_Format_1::tyre_internal_air_temp() const {
	return telemetry_data_->tyre_internal_air_temp();
}

Vector_UInt Data_Car_State_Format_1::tyre_temp_left() const {
	Vector_UInt vu;
	return vu;
}

Vector_UInt Data_Car_State_Format_1::tyre_temp_center() const {
	Vector_UInt vu;
	return vu;
}

Vector_UInt Data_Car_State_Format_1::tyre_temp_right() const {
	Vector_UInt vu;
	return vu;
}

Vector_Float Data_Car_State_Format_1::wheel_local_position_y() const {
	return telemetry_data_->wheel_local_position_y();
}

Vector_Float Data_Car_State_Format_1::ride_height() const {
	return telemetry_data_->ride_height();
}

Vector_Float Data_Car_State_Format_1::suspension_travel() const {
	return telemetry_data_->suspension_travel();
}

Vector_Float Data_Car_State_Format_1::suspension_velocity() const {
	return telemetry_data_->suspension_velocity();
}

Vector_UInt Data_Car_State_Format_1::suspension_ride_height() const {
	Vector_UInt vu;
	return vu;
}

Vector_UInt Data_Car_State_Format_1::air_pressure() const {
	return telemetry_data_->air_pressure();
}

float Data_Car_State_Format_1::engine_speed() const {
	return telemetry_data_->engine_speed();
}

float Data_Car_State_Format_1::engine_torque() const {
	return telemetry_data_->engine_torque();
}

Vector_UInt Data_Car_State_Format_1::wings() const {
	return telemetry_data_->wings();
}

unsigned int Data_Car_State_Format_1::handbrake() const {
	return 0;
}

Vector_String Data_Car_State_Format_1::tyre_compound() const {
	Vector_String vs;
	return vs;
}

float Data_Car_State_Format_1::turbo_boost_pressure() const {
	return 0;
}

unsigned int Data_Car_State_Format_1::brake_bias() const {
	return 0;
}

Vector_Float Data_Car_State_Format_1::full_position() const {
	Vector_Float vf;
	return vf;
}

unsigned int Data_Car_State_Format_1::tick_count() const {
	// not supported in v1
	return 0;
}

};

