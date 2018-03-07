#ifndef PCARS_DATA_SPLIT_TIMES_FORMAT_1_H_
#define PCARS_DATA_SPLIT_TIMES_FORMAT_1_H_

#include "datasplittimes.h"
#include "decodertelemetrydata.h"

namespace pcars {

class Data_Split_Times_Format_1 : public Data_Split_Times {
public:
	Data_Split_Times_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
	virtual ~Data_Split_Times_Format_1() {}

	unsigned int participants_changed_timestamp() const override;
	float event_time_remaining() const override;
	float split_time_ahead() const override;
	float split_time_behind() const override;
	float split_time() const override;

public:
	std::shared_ptr<Decoder_Telemetry_Data> telemetry_data_;
};

}

#endif

