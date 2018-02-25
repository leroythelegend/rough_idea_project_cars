#ifndef PCARS_DATA_GAME_STATE_FORMAT_1_H_
#define PCARS_DATA_GAME_STATE_FORMAT_1_H_

#include "datagamestate.h"
#include "decodertelemetrydata.h"

namespace pcars {

class Data_Game_State_Format_1 : public Data_Game_State {
public:
	Data_Game_State_Format_1(Decoder_Telemetry_Data *);
	virtual ~Data_Game_State_Format_1() {}

	unsigned int session_state() const override;
	unsigned int game_state() const override;
	unsigned int race_state_flags() const override;
	unsigned int pit_mode() const override;
	
private:
	Decoder_Telemetry_Data * telemetry_data_;
};

}

#endif

