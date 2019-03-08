#ifndef PCARS_DATA_INPUT_STATE_FORMAT_1_H_
#define PCARS_DATA_INPUT_STATE_FORMAT_1_H_

#include "datainputstate.h"
#include "decodertelemetrydata.h"

#include <memory>

namespace pcars {

class Data_Input_State_Format_1 : public Data_Input_State {
public:
	Data_Input_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
	virtual ~Data_Input_State_Format_1() {}

	float unfiltered_throttle() const override;
	float unfiltered_brake() const override;
	float unfiltered_steering() const override;
	float unfiltered_clutch() const override;

private:
	std::shared_ptr<Decoder_Telemetry_Data> telemetry_data_;
};

}

#endif

