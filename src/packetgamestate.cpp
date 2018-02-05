#include "packetgamestate.h"

namespace pcars {

Packet_Game_State::Packet_Game_State() {
	add(&packet_base_);
	add(&build_version_);
	add(&game_session_state_);
	add(&ambient_temperature_);
	add(&track_temperature_);
	add(&rain_density_);
	add(&snow_density_);
	add(&wind_speed_);
	add(&wind_direction_x_);
	add(&wind_direction_y_);
}

Packet_Base Packet_Game_State::packet_base() const {
	return packet_base_;
}

unsigned int Packet_Game_State::build_version() const {
	return build_version_.u16();
}

unsigned int Packet_Game_State::game_state() const {
	return game_session_state_.ls3bits();
}

unsigned int Packet_Game_State::sessin_state() const {
	return game_session_state_.ms3bits();
}

int Packet_Game_State::ambient_temperature() const {
	return ambient_temperature_.s8();
}

int Packet_Game_State::track_temperature() const {
	return track_temperature_.s8();
}

unsigned int Packet_Game_State::rain_density() const {
	return rain_density_.u8();
}

unsigned int Packet_Game_State::snow_density() const {
	return snow_density_.u8();
}

int Packet_Game_State::wind_speed() const {
	return wind_speed_.s8();
}

int Packet_Game_State::wind_direction_x() const {
	return wind_direction_x_.s8();
}

int Packet_Game_State::wind_direction_y() const {
	return wind_direction_y_.s8();
}

}

