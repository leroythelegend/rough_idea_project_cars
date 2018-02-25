#ifndef PCARS_DATA_TIMES_FORMAT_1_H_
#define PCARS_DATA_TIMES_FORMAT_1_H_

#include "datatimes.h"
#include "decodertelemetrydata.h"

namespace pcars {

class Data_Times_Format_1 : public Data_Times {
public:
	Data_Times_Format_1(Decoder_Telemetry_Data *);
	virtual ~Data_Times_Format_1() {}

	float current_time() const override;
	float current_sector1_time() const override;
	float current_sector2_time() const override;
	float current_sector3_time() const override;
	float fastest_sector1_time() const override;
	float fastest_sector2_time() const override;
	float fastest_sector3_time() const override;

private:
	Decoder_Telemetry_Data * telemetry_data_;
};

}

#endif

