#include "decodertelemetrydata.h"

namespace pcars {

Decoder_Telemetry_Data::Decoder_Telemetry_Data() {
	add(&buildversion_);
	add(&sequencenum_packettype_);
	add(&sessionstate_gamestate_);
	add(&viewedparticipantindex_);
	add(&numparticipants_);
	add(&unfilteredthrottle_);
	add(&unfilteredbrake_);
	add(&unfilteredsteering_);
	add(&unfilteredclutch_);
	add(&racestateflags_);
	add(&lapsinevent_);
	add(&bestlaptime_);
	add(&lastlaptime_);
	add(&currenttime_);
	add(&splittimeahead_);
	add(&splittimebehind_);
	add(&splittime_);
	add(&eventtimeremaining_);
	add(&personalfastestlaptime_);
	add(&worldfastestlaptime_);
	add(&currentsector1time_);
	add(&currentsector2time_);
	add(&currentsector3time_);
	add(&fastestsector1time_);
	add(&fastestsector2time_);
	add(&fastestsector3time_);
	add(&personalfastestsector1time_);
	add(&personalfastestsector2time_);
	add(&personalfastestsector3time_);
	add(&worldfastestsector1time_);
	add(&worldfastestsector2time_);
	add(&worldfastestsector3time_);
	add(&joypad_);
	add(&highestflagreason_highestflagcolour_);
	add(&pitschedule_pitmode_);
	add(&oiltempcelsius_);
	add(&oilpressurekpa_);
	add(&watertempcelsius_);
	add(&waterpressurekpa_);
	add(&fuelpressurekpa_);
	add(&carflags_);
	add(&fuelcapacity_);
	add(&brake_);
	add(&throttle_);
	add(&clutch_);
	add(&steering_);
	add(&fuellevel_);
	add(&speed_);
	add(&rpm_);
	add(&maxrpm_);
	add(&gearnumgears_);
	add(&boostamount_);
	add(&enforcedpitstoplap_);
	add(&crashstate_);
	add(&odometerkm_);
	add(&orientation_);
	add(&localvelocity_);
	add(&worldvelocity_);
	add(&angularvelocity_);
	add(&localacceleration_);
	add(&worldacceleration_);
	add(&extentscentre_);
	add(&tyreflags_);
	add(&terrain_);
	add(&tyrey_);
	add(&tyrerps_);
	add(&tyreslipspeed_);
	add(&tyretemp_);
	add(&tyregrip_);
	add(&tyreheightaboveground_);
	add(&tyrelateralstiffness_);
	add(&tyrewear_);
	add(&brakedamage_);
	add(&suspensiondamage_);
	add(&braketempcelsius_);
	add(&tyretreadtemp_);
	add(&tyrelayertemp_);
	add(&tyrecarcasstemp_);
	add(&tyrerimtemp_);
	add(&tyreinternalairtemp_);
	add(&wheellocalpositiony_);
	add(&rideheight_);
	add(&suspensiontravel_);
	add(&suspensionvelocity_);
	add(&airpressure_);
	add(&enginespeed_);
	add(&enginetorque_);
	add(&aerodamage_);
	add(&enginedamage_);
	add(&ambienttemperature_);
	add(&tracktemperature_);
	add(&raindensity_);
	add(&windspeed_);
	add(&winddirectionx_);
	add(&winddirectiony_);
	add(&paricipantinfo_);
	add(&tracklength_);
	add(&wings_);
	add(&dpad_);
}

Decoder_Telemetry_Data::~Decoder_Telemetry_Data() {
}

unsigned int Decoder_Telemetry_Data::build_version() const {
	return buildversion_.u16();
}

unsigned int Decoder_Telemetry_Data::sequence_number() const {
	return sequencenum_packettype_.ms6bits();
}

Packet_Type Decoder_Telemetry_Data::packet_type() const{
	return static_cast<Packet_Type>(sequencenum_packettype_.ls2bits());
}

Session_State Decoder_Telemetry_Data::session_state() const {
	return static_cast<Session_State>(sessionstate_gamestate_.ms3bits());
}

Game_State Decoder_Telemetry_Data::game_state() const {
	return static_cast<Game_State>(sessionstate_gamestate_.ls3bits());
}

int Decoder_Telemetry_Data::viewed_participant_index() const {
	return viewedparticipantindex_.s8();
}

int Decoder_Telemetry_Data::num_participants() const {
	return numparticipants_.s8();
}

float Decoder_Telemetry_Data::unfiltered_throttle() const {
	return unfilteredthrottle_.f1tof0();
}

float Decoder_Telemetry_Data::unfiltered_brake() const {
	return unfilteredbrake_.f1tof0();
}

float Decoder_Telemetry_Data::unfiltered_steering() const {
	return unfilteredsteering_.neg1f_pos1f();
}

float Decoder_Telemetry_Data::unfiltered_clutch() const {
	return unfilteredclutch_.f1tof0();
}

Race_State Decoder_Telemetry_Data::race_state_flags() const {
	return static_cast<Race_State>(racestateflags_.ls3bits());
}

unsigned int Decoder_Telemetry_Data::laps_in_event() const {
	return lapsinevent_.u8();
}

float Decoder_Telemetry_Data::best_lap_time() const {
	return bestlaptime_.f32();
}

float Decoder_Telemetry_Data::last_lap_time() const {
	return lastlaptime_.f32();
}

float Decoder_Telemetry_Data::current_time() const {
	return currenttime_.f32();
}

float Decoder_Telemetry_Data::split_time_ahead() const {
	return splittimeahead_.f32();
}

float Decoder_Telemetry_Data::split_time_behind() const {
	return splittimebehind_.f32();
}

float Decoder_Telemetry_Data::split_time() const {
	return splittime_.f32();
}

float Decoder_Telemetry_Data::event_time_remaining() const {
	return eventtimeremaining_.f32();
}

float Decoder_Telemetry_Data::personal_fastest_lap_time() const {
	return personalfastestlaptime_.f32();
}

float Decoder_Telemetry_Data::world_fastest_lap_time() const {
	return worldfastestlaptime_.f32();
}

float Decoder_Telemetry_Data::current_sector1_time() const {
	return currentsector1time_.f32();
}

float Decoder_Telemetry_Data::current_sector2_time() const {
	return currentsector2time_.f32();
}

float Decoder_Telemetry_Data::current_sector3_time() const {
	return currentsector3time_.f32();
}

float Decoder_Telemetry_Data::fastest_sector1_time() const {
	return fastestsector1time_.f32();
}

float Decoder_Telemetry_Data::fastest_sector2_time() const {
	return fastestsector2time_.f32();
}

float Decoder_Telemetry_Data::fastest_sector3_time() const {
	return fastestsector3time_.f32();
}

float Decoder_Telemetry_Data::personal_fastest_sector1_time() const {
	return personalfastestsector1time_.f32();
}

float Decoder_Telemetry_Data::personal_fastest_sector2_time() const {
	return personalfastestsector2time_.f32();
}

float Decoder_Telemetry_Data::personal_fastest_sector3_time() const {
	return personalfastestsector3time_.f32();
}

float Decoder_Telemetry_Data::world_fastest_sector1_time() const {
	return worldfastestsector1time_.f32();
}

float Decoder_Telemetry_Data::world_fastest_sector2_time() const {
	return worldfastestsector2time_.f32();
}

float Decoder_Telemetry_Data::world_fastest_sector3_time() const {
	return worldfastestsector3time_.f32();
}

Vector_Bool Decoder_Telemetry_Data::joy_pad() const {
	return joypad_.mask_16bit();
}

Flag_Reason Decoder_Telemetry_Data::flag_reason() const {
	return static_cast<Flag_Reason>(highestflagreason_highestflagcolour_.ls3bits());
}

Flag_Colour Decoder_Telemetry_Data::flag_colour() const {
	return static_cast<Flag_Colour>(highestflagreason_highestflagcolour_.ms2bits());
}

Pit_Mode Decoder_Telemetry_Data::pit_mode() const {
	return static_cast<Pit_Mode>(pitschedule_pitmode_.ls3bits());
}

Pit_Schedule Decoder_Telemetry_Data::pit_schedule() const {
	return static_cast<Pit_Schedule>(pitschedule_pitmode_.ms2bits());
}

float Decoder_Telemetry_Data::oil_temp_celsius() const {
	return static_cast<float>(oiltempcelsius_.s16());
}

float Decoder_Telemetry_Data::oil_pressure_kpa() const {
	return static_cast<float>(oilpressurekpa_.u16());
}

float Decoder_Telemetry_Data::water_temp_celsius() const {
	return static_cast<float>(watertempcelsius_.s16());
}

float Decoder_Telemetry_Data::water_pressure_kpa() const {
	return static_cast<float>(oilpressurekpa_.u16());
}

float Decoder_Telemetry_Data::fuel_pressure_kpa() const {
	return static_cast<float>(fuelpressurekpa_.u16());
}

Vector_Bool Decoder_Telemetry_Data::car_flags() const {
	return carflags_.mask_8bit();
}

unsigned int Decoder_Telemetry_Data::fuel_capacity() const {
	return fuelcapacity_.u8();
}

unsigned int Decoder_Telemetry_Data::brake() const {
	return brake_.u8();
}

unsigned int Decoder_Telemetry_Data::throttle() const {
	return throttle_.u8();
}

float Decoder_Telemetry_Data::clutch() const {
	return clutch_.f1tof0();
}

int Decoder_Telemetry_Data::steering() const {
	return steering_.s8();
}

float Decoder_Telemetry_Data::fuel_level() const {
	return fuellevel_.f32();
}

float Decoder_Telemetry_Data::speed() const {
	return speed_.f32();
}

unsigned int Decoder_Telemetry_Data::rpm() const {
	return rpm_.u16();
}

unsigned int Decoder_Telemetry_Data::max_rpm() const {
	return maxrpm_.u16();
}

int Decoder_Telemetry_Data::num_gears() const {
	return gearnumgears_.ms4bits();
}

int Decoder_Telemetry_Data::gear() const {
	return gearnumgears_.ls4bits();
}

float Decoder_Telemetry_Data::boost_amount() const {
	return static_cast<float>(boostamount_.u8());
}

int Decoder_Telemetry_Data::enforced_pit_stop_lap() const {
	return enforcedpitstoplap_.s8();
}

Crash_State Decoder_Telemetry_Data::crash_state() const {
	return static_cast<Crash_State>(crashstate_.ls3bits());
}

float Decoder_Telemetry_Data::odometer_km() const {
	return odometerkm_.f32();
}

Vector_Float Decoder_Telemetry_Data::orientation() const {
	return orientation_.times3_float();
}

Vector_Float Decoder_Telemetry_Data::local_velocity() const {
	return localvelocity_.times3_float();
}

Vector_Float Decoder_Telemetry_Data::world_velocity() const {
	return worldvelocity_.times3_float();
}

Vector_Float Decoder_Telemetry_Data::angular_velocity() const {
	return angularvelocity_.times3_float();
}

Vector_Float Decoder_Telemetry_Data::local_acceleration() const {
	return localacceleration_.times3_float();
}

Vector_Float Decoder_Telemetry_Data::world_acceleration() const {
	return worldacceleration_.times3_float();
}

Vector_Float Decoder_Telemetry_Data::extents_centre() const {
	return extentscentre_.times3_float();
}

Vector_UInt Decoder_Telemetry_Data::tyre_flags() const {
	return tyreflags_.times4_u8();
}

Vector_UInt Decoder_Telemetry_Data::terrain() const {
	return terrain_.times4_u8();
}

Vector_Float Decoder_Telemetry_Data::tyre_y() const {
	return tyrey_.times4_float();
}

Vector_Float Decoder_Telemetry_Data::tyre_rps() const {
	return tyrerps_.times4_float();
}

Vector_Float Decoder_Telemetry_Data::tyre_slip_speed() const {
	return tyreslipspeed_.times4_float();
}

Vector_UInt Decoder_Telemetry_Data::tyre_temp() const {
	return tyretemp_.times4_u8();
}

Vector_UInt Decoder_Telemetry_Data::tyre_grip() const {
	return tyregrip_.times4_u8();
}

Vector_Float Decoder_Telemetry_Data::tyre_height_above_ground() const {
	return tyreheightaboveground_.times4_float();
}

Vector_Float Decoder_Telemetry_Data::tyre_lateral_stiffness() const {
	return tyrelateralstiffness_.times4_float();
}

Vector_UInt Decoder_Telemetry_Data::tyre_wear() const {
	return tyrewear_.times4_u8();
}

Vector_UInt Decoder_Telemetry_Data::brake_damage() const {
	return brakedamage_.times4_u8();
}

Vector_UInt Decoder_Telemetry_Data::suspension_damage() const {
	return suspensiondamage_.times4_u8();
}

Vector_Int Decoder_Telemetry_Data::brake_temp_celsius() const {
	return braketempcelsius_.times4_s16();
}

Vector_UInt Decoder_Telemetry_Data::tyre_tread_temp() const {
	return tyretreadtemp_.times4_u16();
}

Vector_UInt Decoder_Telemetry_Data::tyre_layer_temp() const {
	return tyrelayertemp_.times4_u16();
}

Vector_UInt Decoder_Telemetry_Data::tyre_carcass_temp() const {
	return tyrecarcasstemp_.times4_u16();
}

Vector_UInt Decoder_Telemetry_Data::tyre_rim_temp() const {
	return tyrerimtemp_.times4_u16();
}

Vector_UInt Decoder_Telemetry_Data::tyre_internal_air_temp() const {
	return tyreinternalairtemp_.times4_u16();
}

Vector_Float Decoder_Telemetry_Data::wheel_local_position_y() const {
	return wheellocalpositiony_.times4_float();
}

Vector_Float Decoder_Telemetry_Data::ride_height() const {
	return rideheight_.times4_float();
}

Vector_Float Decoder_Telemetry_Data::suspension_travel() const {
	return suspensiontravel_.times4_float();
}

Vector_Float Decoder_Telemetry_Data::suspension_velocity() const {
	return suspensionvelocity_.times4_float();
}

Vector_UInt Decoder_Telemetry_Data::air_pressure() const {
	return airpressure_.times4_u16();
}

float Decoder_Telemetry_Data::engine_speed() const {
	return enginespeed_.f32();
}

float Decoder_Telemetry_Data::engine_torque() const {
	return enginetorque_.f32();
}

float Decoder_Telemetry_Data::aero_damage() const {
	return static_cast<float>(aerodamage_.u8());
}

float Decoder_Telemetry_Data::engine_damage() const {
	return static_cast<float>(enginedamage_.u8());
}

float Decoder_Telemetry_Data::ambient_temperature() const {
	return static_cast<float>(ambienttemperature_.s8());
}

float Decoder_Telemetry_Data::track_temperature() const {
	return static_cast<float>(tracktemperature_.s8());
}

float Decoder_Telemetry_Data::rain_density() const {
	return static_cast<float>(raindensity_.u8());
}

float Decoder_Telemetry_Data::wind_speed() const {
	return static_cast<float>(windspeed_.s8());
}

float Decoder_Telemetry_Data::wind_direction_x() const {
	return static_cast<float>(winddirectionx_.s8());
}

float Decoder_Telemetry_Data::wind_direction_y() const {
	return static_cast<float>(winddirectiony_.s8());
}

Decoder_Telemetry_Data::Vector_Participant_Info Decoder_Telemetry_Data::participant_info() const {
	return paricipantinfo_.participant_info();
}

unsigned int Decoder_Telemetry_Data::track_length() const {
	return tracklength_.f32();
}

Vector_UInt Decoder_Telemetry_Data::wings() const {
	return wings_.times2_U8();
}

Vector_Bool Decoder_Telemetry_Data::dpad() const {
	return dpad_.mask_8bit();
}

}

