#ifndef PCARS_PACKET_TELEMETRY_DATA_H_
#define PCARS_PACKET_TELEMETRY_DATA_H_

#include "decodercomposite.h"

#include "packetbase.h"

#include "decoderu16.h"
#include "decoders16.h"
#include "decoder3bit3bit.h"
#include "decoders8.h"
#include "decoderu8.h"
#include "decoderf32.h"
#include "decoder4timesfloat.h"
#include "decoder3timesfloat.h"
#include "decoder4timesu8.h"
#include "decoder4timess16.h"
#include "decoder4timesu16.h"
#include "decoder4timeschar40.h"
#include "decoder3timess16.h"
#include "decoder2timesu8.h"
#include "decoder4bit4bit.h"


namespace pcars {

class Packet_Telemetry_Data : public Decoder_Composite {
public:
	Packet_Telemetry_Data();
	virtual ~Packet_Telemetry_Data() {}

	Packet_Base packet_base() const;
	int viewed_participant_index() const;
	unsigned int unfiltered_throttle() const;
	unsigned int unfiltered_brake() const;
	int unfiltered_steering() const;
	unsigned int unfiltered_clutch() const;
	unsigned int car_flags() const;	
	int oil_temp_celsius() const;
	unsigned int oil_pressure_kpa() const;
	int water_temp_celsius() const;
	unsigned int water_pressure_kpa() const;
	unsigned int fuel_pressure_kpa() const;
	unsigned int fuel_capacity() const;
	unsigned int brake() const;
	unsigned int throttle() const;
	unsigned int clutch() const;
	float fuel_level() const;
	float speed() const;
	unsigned int rpm() const;
	unsigned int max_rpm() const;
	int steering() const;
	unsigned int gears() const;
	unsigned int gear() const;
	unsigned int boost_amount() const;
	unsigned int crash_state() const;
	float odometer_km() const;
	Vector_Float orientation() const;
	Vector_Float local_velocity() const;
	Vector_Float world_velocity() const;
	Vector_Float angular_velocity() const;
	Vector_Float local_acceleration() const;
	Vector_Float world_acceleration() const;
	Vector_Float extents_centre() const;
	Vector_UInt tyre_flags() const;
	Vector_UInt terrain() const;
	Vector_Float tyre_y() const;
	Vector_Float tyre_rps() const;
	Vector_UInt tyre_temp() const;
	Vector_Float tyre_height_above_ground() const;
	Vector_UInt tyre_wear() const;
	Vector_UInt brake_damage() const;
	Vector_UInt suspension_damage() const;
	Vector_Int brake_temp_celsius() const;
	Vector_UInt tyre_tread_temp() const;
	Vector_UInt tyre_layer_temp() const;
	Vector_Int tyre_carcass_temp() const;
	Vector_Int tyre_rim_temp() const;
	Vector_Int tyre_internal_air_temp() const;
	Vector_UInt tyre_temp_left() const;
	Vector_UInt tyre_temp_center() const;
	Vector_UInt tyre_temp_right() const;	
	Vector_Float wheel_local_position_y() const;
	Vector_Float ride_height() const;
	Vector_Float suspension_travel() const;
	Vector_Float suspension_velocity() const;
	Vector_UInt suspension_ride_height() const;
	Vector_UInt air_pressure() const;
	float engine_speed() const;
	float engine_torque() const;
	Vector_UInt wings() const;
	unsigned int handbrake() const;
	unsigned int aero_damage() const;
	unsigned int engine_damage() const;
	unsigned int joy_pad_0() const;
	unsigned int  d_pad() const;
	Vector_String tyre_compound() const;
	float turbo_boost_pressure() const;
	Vector_Float full_position() const;
	unsigned int brake_bias() const;

private:
	Packet_Base packet_base_;
	Decoder_S8 viewed_participant_index_;
	Decoder_U8 unfiltered_throttle_;
	Decoder_U8 unfiltered_brake_;
	Decoder_S8 unfiltered_steering_;
	Decoder_U8 unfiltered_clutch_;
	Decoder_U8 car_flags_;	
	Decoder_S16 oil_temp_celsius_;
	Decoder_U16 oil_pressure_kpa_;
	Decoder_S16 water_temp_celsius_;
	Decoder_U16 water_pressure_kpa_;
	Decoder_U16 fuel_pressure_kpa_;
	Decoder_U8 fuel_capacity_;
	Decoder_U8 brake_;
	Decoder_U8 throttle_;
	Decoder_U8 clutch_;
	Decoder_F32 fuel_level_;
	Decoder_F32 speed_;
	Decoder_U16 rpm_;
	Decoder_U16 max_rpm_;
	Decoder_S8 steering_;
	Decoder_4bit_4bit gear_num_gears_;
	Decoder_U8 boost_amount_;
	Decoder_U8 crash_state_;
	Decoder_F32 odometer_km_;
	Decoder_3Times_Float orientation_;
	Decoder_3Times_Float local_velocity_;
	Decoder_3Times_Float world_velocity_;
	Decoder_3Times_Float angular_velocity_;
	Decoder_3Times_Float local_acceleration_;
	Decoder_3Times_Float world_acceleration_;
	Decoder_3Times_Float extents_centre_;
	Decoder_4Times_U8 tyre_flags_;
	Decoder_4Times_U8 terrain_;
	Decoder_4Times_Float tyre_y_;
	Decoder_4Times_Float tyre_rps_;
	Decoder_4Times_U8 tyre_temp_;
	Decoder_4Times_Float tyre_height_above_ground_;
	Decoder_4Times_U8 tyre_wear_;
	Decoder_4Times_U8 brake_damage_;
	Decoder_4Times_U8 suspension_damage_;
	Decoder_4Times_S16 brake_temp_celsius_;
	Decoder_4Times_U16 tyre_tread_temp_;
	Decoder_4Times_U16 tyre_layer_temp_;
	Decoder_4Times_S16 tyre_carcass_temp_;
	Decoder_4Times_S16 tyre_rim_temp_;
	Decoder_4Times_S16 tyre_internal_air_temp_;
	Decoder_4Times_U16 tyre_temp_left_;
	Decoder_4Times_U16 tyre_temp_center_;
	Decoder_4Times_U16 tyre_temp_right_;	
	Decoder_4Times_Float wheel_local_position_y_;
	Decoder_4Times_Float ride_height_;
	Decoder_4Times_Float suspension_travel_;
	Decoder_4Times_Float suspension_velocity_;
	Decoder_4Times_U16 suspension_ride_height_;
	Decoder_4Times_U16 air_pressure_;
	Decoder_F32 engine_speed_;
	Decoder_F32 engine_torque_;
	Decoder_2Times_U8 wings_;
	Decoder_U8 handbrake_;
	Decoder_U8 aero_damage_;
	Decoder_U8 engine_damage_;
	Decoder_U32 joy_pad_0_;
	Decoder_U8  d_pad_;
	Decoder_4Times_40Char tyre_compound_;
	Decoder_F32 turbo_boost_pressure_;
	Decoder_3Times_Float full_position_;
	Decoder_U8 brake_bias_;

};

}

#endif

