#ifndef PCARS_DECODER_TELEMETRY_DATA_H_
#define PCARS_DECODER_TELEMETRY_DATA_H_

#include "decodercomposite.h"

#include "decoderu16.h"
#include "decoder6bit2bit.h"
#include "decoder3bit3bit.h"
#include "decoders8.h"
#include "decoder1fto0f.h"
#include "decoderneg1ftopos1f.h"
#include "decoder3bit.h"
#include "decoderu8.h"
#include "decoderf32.h"
#include "decoder16bitmask.h"
#include "decoder2bit3bit.h"
#include "decoder3timesfloat.h"
#include "decoders16.h"
#include "decoder8bitmask.h"
#include "decoder4bit4bit.h"
#include "consts.h"
#include "decoder4timesu8.h"
#include "decoder4timesfloat.h"
#include "decoder4timess16.h"
#include "decoder4timesu16.h"
#include "decoderparticipantinfo.h"
#include "decoder56participantinfo.h"
#include "decoder2timesu8.h"
#include "decoderu32.h"

namespace pcars {

class Decoder_Telemetry_Data : public Decoder_Composite {
public:
	using Vector_Participant_Info = std::vector<Decoder_Participant_Info>;

	Decoder_Telemetry_Data();
	virtual ~Decoder_Telemetry_Data();

	uint16_t build_version() const;
	unsigned int sequence_number() const;
	Packet_Type packet_type() const;
	Session_State session_state() const;
	Game_State game_state() const;
	int8_t viewed_participant_index() const;
	int8_t num_participants() const;
	float unfiltered_throttle() const;
	float unfiltered_brake() const;
	float unfiltered_steering() const;
	float unfiltered_clutch() const;
	Race_State race_state_flags() const;
	uint8_t laps_in_event() const;
	float best_lap_time() const;
	float last_lap_time() const;
	float current_time() const;
	float split_time_ahead() const;
	float split_time_behind() const;
	float split_time() const;
	float event_time_remaining() const;
	float personal_fastest_lap_time() const;
	float world_fastest_lap_time() const;
	float current_sector1_time() const;
	float current_sector2_time() const;
	float current_sector3_time() const;
	float fastest_sector1_time() const;
	float fastest_sector2_time() const;
	float fastest_sector3_time() const;
	float personal_fastest_sector1_time() const;
	float personal_fastest_sector2_time() const;
	float personal_fastest_sector3_time() const;
	float world_fastest_sector1_time() const;
	float world_fastest_sector2_time() const;
	float world_fastest_sector3_time() const;
	Vector_Bool joy_pad() const;
	Flag_Reason flag_reason() const;
	Flag_Colour flag_colour() const;
	Pit_Mode pit_mode() const;
	Pit_Schedule pit_schedule() const;
	float oil_temp_celsius() const;
	float oil_pressure_kpa() const;
	float water_temp_celsius() const;
	float water_pressure_kpa() const;
	float fuel_pressure_kpa() const;
	Vector_Bool car_flags() const;
	unsigned int fuel_capacity() const;
	unsigned int brake() const;
	unsigned int throttle() const;
	float clutch() const;
	int steering() const;
	float fuel_level() const;
	float speed() const;
	unsigned int rpm() const;
	unsigned int max_rpm() const;
	int num_gears() const;
	int gear() const;
	float boost_amount() const;
	int8_t enforced_pit_stop_lap() const;
	Crash_State crash_state() const;
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
	Vector_Float tyre_slip_speed() const;
	Vector_Float tyre_temp() const;
	Vector_Float tyre_grip() const;
	Vector_Float tyre_height_above_ground() const;
	Vector_Float tyre_lateral_stiffness() const;
	Vector_Float tyre_wear() const;
	Vector_Float brake_damage() const;
	Vector_Float suspension_damage() const;
	Vector_Float brake_temp_celsius() const;
	Vector_Float tyre_tread_temp() const;
	Vector_Float tyre_layer_temp() const;
	Vector_Float tyre_carcass_temp() const;
	Vector_Float tyre_rim_temp() const;
	Vector_Float tyre_internal_air_temp() const;
	Vector_Float wheel_local_position_y() const;
	Vector_Float ride_height() const;
	Vector_Float suspension_travel() const;
	Vector_Float suspension_velocity() const;
	Vector_Float air_pressure() const;
	float engine_speed() const;
	float engine_torque() const;
	float aero_damage() const;
	float engine_damage() const;
	float ambient_temperature() const;
	float track_temperature() const;
	float rain_density() const;
	float wind_speed() const;
	float wind_direction_x() const;
	float wind_direction_y() const;
	Vector_Participant_Info participant_info() const;
	unsigned int track_length() const;
	Vector_Float wings() const;
	Vector_Bool dpad() const;

private:
	Decoder_U16 buildversion_;
	Decoder_6bit_2bit sequencenum_packettype_;
	Decoder_3bit_3bit sessionstate_gamestate_;
	Decoder_S8 viewedparticipantindex_;
	Decoder_S8 numparticipants_;
	Decoder_1Fto0F unfilteredthrottle_;
	Decoder_1Fto0F unfilteredbrake_;
	Decoder_Neg1F_To_Pos1F unfilteredsteering_;
	Decoder_1Fto0F unfilteredclutch_;
	Decoder_3bit racestateflags_;
	Decoder_U8 lapsinevent_;
	Decoder_F32 bestlaptime_;
	Decoder_F32 lastlaptime_;
	Decoder_F32 currenttime_;
	Decoder_F32 splittimeahead_;
	Decoder_F32 splittimebehind_;
	Decoder_F32 splittime_;
	Decoder_F32 eventtimeremaining_;
	Decoder_F32 personalfastestlaptime_;
	Decoder_F32 worldfastestlaptime_;
	Decoder_F32 currentsector1time_;
	Decoder_F32 currentsector2time_;
	Decoder_F32 currentsector3time_;
	Decoder_F32 fastestsector1time_;
	Decoder_F32 fastestsector2time_;
	Decoder_F32 fastestsector3time_;
	Decoder_F32 personalfastestsector1time_;
	Decoder_F32 personalfastestsector2time_;
	Decoder_F32 personalfastestsector3time_;
	Decoder_F32 worldfastestsector1time_;
	Decoder_F32 worldfastestsector2time_;
	Decoder_F32 worldfastestsector3time_;
	Decoder_16bit_Mask joypad_;
	Decoder_2bit_3bit highestflagreason_highestflagcolour_;
	Decoder_2bit_3bit pitschedule_pitmode_;
	Decoder_S16 oiltempcelsius_;
	Decoder_U16 oilpressurekpa_;
	Decoder_S16 watertempcelsius_;
	Decoder_U16 waterpressurekpa_;
	Decoder_U16 fuelpressurekpa_;
	Decoder_8bit_Mask carflags_;
	Decoder_U8 fuelcapacity_;
	Decoder_U8 brake_;
	Decoder_U8 throttle_;
	Decoder_1Fto0F clutch_;
	Decoder_S8 steering_;
	Decoder_F32 fuellevel_;
	Decoder_F32 speed_;
	Decoder_U16 rpm_;
	Decoder_U16 maxrpm_;
	Decoder_4bit_4bit gearnumgears_;
	Decoder_U8 boostamount_;
	Decoder_S8 enforcedpitstoplap_;
	Decoder_3bit_3bit crashstate_;
	Decoder_F32 odometerkm_;
	Decoder_3Times_Float orientation_;
	Decoder_3Times_Float localvelocity_;
	Decoder_3Times_Float worldvelocity_;
	Decoder_3Times_Float angularvelocity_;
	Decoder_3Times_Float localacceleration_;
	Decoder_3Times_Float worldacceleration_;
	Decoder_3Times_Float extentscentre_;

	Decoder_4Times_U8 tyreflags_;
	Decoder_4Times_U8 terrain_;
	Decoder_4Times_Float tyrey_;
	Decoder_4Times_Float tyrerps_;
	Decoder_4Times_Float tyreslipspeed_;
	Decoder_4Times_U8 tyretemp_;
	Decoder_4Times_U8 tyregrip_;
	Decoder_4Times_Float tyreheightaboveground_;
	Decoder_4Times_Float tyrelateralstiffness_;
	Decoder_4Times_U8 tyrewear_;
	Decoder_4Times_U8 brakedamage_;
	Decoder_4Times_U8 suspensiondamage_;
	Decoder_4Times_S16 braketempcelsius_;
	Decoder_4Times_U16 tyretreadtemp_;
	Decoder_4Times_U16 tyrelayertemp_;
	Decoder_4Times_U16 tyrecarcasstemp_;
	Decoder_4Times_U16 tyrerimtemp_;
	Decoder_4Times_U16 tyreinternalairtemp_;
	Decoder_4Times_Float wheellocalpositiony_;
	Decoder_4Times_Float rideheight_;
	Decoder_4Times_Float suspensiontravel_;
	Decoder_4Times_Float suspensionvelocity_;
	Decoder_4Times_U16 airpressure_;

	Decoder_F32 enginespeed_;
	Decoder_F32 enginetorque_;

	Decoder_U8 aerodamage_;
	Decoder_U8 enginedamage_;

	Decoder_S8 ambienttemperature_;
	Decoder_S8 tracktemperature_;
	Decoder_U8 raindensity_;
	Decoder_S8 windspeed_;
	Decoder_S8 winddirectionx_;
	Decoder_S8 winddirectiony_;

	Decoder_56_Participant_Info paricipantinfo_;

	Decoder_F32 tracklength_;

	Decoder_2Times_U8 wings_;

	Decoder_8bit_Mask dpad_;
};

}

#endif
