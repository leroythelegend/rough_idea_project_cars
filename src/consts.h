#ifndef PCARS_CONSTS_H_
#define PCARS_CONSTS_H_

#include <cstdint>

#include <vector>
#include <string>

namespace pcars {

using Position = unsigned int;
using Amount = unsigned int;
using Port = unsigned int;
using Lap_Number = int;

using PCars_Data = std::vector<unsigned char>;

using Vector_Float = std::vector<float>;
using Vector_S16 = std::vector<int16_t>;
using Vector_String = std::vector<std::string>;
using Vector_Bool = std::vector<bool>;
using Vector_U8 = std::vector<uint8_t>;
using Vector_U16 = std::vector<uint16_t>;
using Vector_UInt = std::vector<unsigned int>;

enum class Packet_Type {
	PACKET_TYPE_TELEMETRY,
	PACKET_TYPE_PARTICIPANT_INFO_STRINGS,
	PACKET_TYPE_PARTICIPANT_INFO_STRINGS_ADDITIONAL
};

enum class Game_State {
	GAME_EXITED = 0,
	GAME_FRONT_END,
	GAME_INGAME_PLAYING,
	GAME_INGAME_PAUSED,
	GAME_MAX
};

enum class Session_State {
	SESSION_INVALID = 0,
	SESSION_PRACTICE,
	SESSION_TEST,
	SESSION_QUALIFY,
	SESSION_FORMATION_LAP,
	SESSION_RACE,
	SESSION_TIME_ATTACK,
	SESSION_MAX
};

enum class Race_State {
	RACESTATE_INVALID = 0,
	RACESTATE_NOT_STARTED,
	RACESTATE_RACING,
	RACESTATE_FINISHED,
	RACESTATE_DISQUALIFIED,
	RACESTATE_RETIRED,
	RACESTATE_DNF,
	RACESTATE_MAX
};

enum class Flag_Colour {
	FLAG_COLOUR_NONE = 0,
	FLAG_COLOUR_GREEN,
	FLAG_COLOUR_BLUE,
	FLAG_COLOUR_WHITE,
	FLAG_COLOUR_YELLOW,
	FLAG_COLOUR_DOUBLE_YELLOW,
	FLAG_COLOUR_BLACK,
	FLAG_COLOUR_CHEQUERED,
	FLAG_COLOUR_MAX
};

enum class Flag_Reason {
	FLAG_REASON_NONE = 0,
	FLAG_REASON_SOLO_CRASH,
	FLAG_REASON_VEHICLE_CRASH,
	FLAG_REASON_VEHICLE_OBSTRUCTION,
	FLAG_REASON_MAX
};

enum class Pit_Mode {
	PIT_MODE_NONE = 0,
	PIT_MODE_DRIVING_INTO_PITS,
	PIT_MODE_IN_PIT,
	PIT_MODE_DRIVING_OUT_OF_PITS,
	PIT_MODE_IN_GARAGE,
	PIT_MODE_MAX
};

enum class Pit_Schedule {
	PIT_SCHEDULE_NONE = 0,
	PIT_SCHEDULE_STANDARD,
	PIT_SCHEDULE_DRIVE_THROUGH,
	PIT_SCHEDULE_STOP_GO,
	PIT_SCHEDULE_MAX
};

enum class Car_Flags {
	CAR_HEADLIGHT = 0,
	CAR_ENGINE_ACTIVE,
	CAR_ENGINE_WARNING,
	CAR_SPEED_LIMITER,
	CAR_ABS,
	CAR_HANDBRAKE,
	CAR_STABILITY,
	CAR_TRACTION_CONTROL
};

enum class Crash_State {
	CRASH_DAMAGE_NONE = 0,
	CRASH_DAMAGE_OFFTRACK,
	CRASH_DAMAGE_LARGE_PROP,
	CRASH_DAMAGE_SPINNING,
	CRASH_DAMAGE_ROLLING,
	CRASH_MAX
};

}

#endif

