#ifndef PCARS_DATA_DAMAGE_STATE_FORMAT_1_H_
#define PCARS_DATA_DAMAGE_STATE_FORMAT_1_H_

#include "datadamagestate.h"
#include "decodertelemetrydata.h"

namespace pcars {

class Data_Damage_State_Format_1 : public Data_Damage_State {
public:
	Data_Damage_State_Format_1(Decoder_Telemetry_Data *);
	virtual ~Data_Damage_State_Format_1() {}

	Vector_UInt brake_damage() const override;
	Vector_UInt suspension_damage() const override;
	unsigned int aero_damage() const override;
	unsigned int engine_damage() const override;

private:
	Decoder_Telemetry_Data * telemetry_data_;
};

}

#endif

