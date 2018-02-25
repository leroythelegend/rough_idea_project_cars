#ifndef PCARS_DATA_CONTROL_STATE_FORMAT_1_H_
#define PCARS_DATA_CONTROL_STATE_FORMAT_1_H_

#include "datacontrolstate.h"
#include "decodertelemetrydata.h"

namespace pcars {

class Data_Control_State_Format_1 : public Data_Control_State {
public:
	Data_Control_State_Format_1(Decoder_Telemetry_Data *);
	virtual ~Data_Control_State_Format_1() {}

	unsigned int joy_pad_0() const override;
	unsigned int d_pad() const override;

private:
	Decoder_Telemetry_Data * telemetry_data_;
};

}

#endif

