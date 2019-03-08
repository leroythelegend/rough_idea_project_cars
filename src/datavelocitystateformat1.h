#ifndef PCARS_DATA_VELOCITY_STATE_FORMAT_1_H_
#define PCARS_DATA_VELOCITY_STATE_FORMAT_1_H_

#include "datavelocitystate.h"
#include "decodertelemetrydata.h"

#include <memory>

namespace pcars {

class Data_Velocity_State_Format_1 : public Data_Velocity_State {
public:
	Data_Velocity_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
	virtual ~Data_Velocity_State_Format_1() {}

	Vector_Float orientation() const override;
	Vector_Float local_velocity() const override;
	Vector_Float world_velocity() const override;
	Vector_Float angular_velocity() const override;
	Vector_Float local_acceleration() const override;
	Vector_Float world_acceleration() const override;
	Vector_Float extents_centre() const override;

private:
	std::shared_ptr<Decoder_Telemetry_Data> telemetry_data_;
};

}

#endif

