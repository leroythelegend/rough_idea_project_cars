#ifndef PCARS_DATA_SPLIT_TIMES_FORMAT_2_H_
#define PCARS_DATA_SPLIT_TIMES_FORMAT_2_H_

#include "datasplittimes.h"
#include "packet.h"

namespace pcars {

class Data_Split_Times_Format_2 : public Data_Split_Times {
public:
	Data_Split_Times_Format_2(const Packet&);
	virtual ~Data_Split_Times_Format_2() {}

	unsigned int participants_changed_timestamp() const override;
	float event_time_remaining() const override;
	float split_time_ahead() const override;
	float split_time_behind() const override;
	float split_time() const override;

public:
	Packet packet_;
};

}

#endif

