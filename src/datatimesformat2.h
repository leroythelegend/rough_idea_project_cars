#ifndef PCARS_DATA_TIMES_FORMAT_2_H_
#define PCARS_DATA_TIMES_FORMAT_2_H_

#include "datatimes.h"
#include "packet.h"

namespace pcars {

class Data_Times_Format_2 : public Data_Times {
public:
	Data_Times_Format_2(const Packet&);
	virtual ~Data_Times_Format_2() {}

	float current_time() const override;
	float current_sector1_time() const override;
	float current_sector2_time() const override;
	float current_sector3_time() const override;
	float fastest_sector1_time() const override;
	float fastest_sector2_time() const override;
	float fastest_sector3_time() const override;

private:
	Packet packet_;
};

}

#endif

