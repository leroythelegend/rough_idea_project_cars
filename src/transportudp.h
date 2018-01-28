#ifndef PCARS_TRANSPORT_UDP_H_
#define PCARS_TRANSPORT_UDP_H_

#include "transport.h"

namespace pcars {

class Transport_UDP : public Transport {
public:
	Transport_UDP(const Port);
	virtual ~Transport_UDP();

	PCars_Data read(const Amount) override;
	void write(const PCars_Data &) override;

private:
	int socketfd_;
};

}

#endif
