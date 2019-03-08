#ifndef PCARS_LIVE_DATA_H_
#define PCARS_LIVE_DATA_H_

#include "decoder.h"
#include "data.h"

#include <memory>

namespace pcars { 

class Live {
public:
	virtual ~Live() {}

	virtual void live(std::shared_ptr<Data>) = 0;
};

class Live_Feed : public Live {
public:
	virtual ~Live_Feed() {}

	void live(std::shared_ptr<Data>) override;
};

}

#endif

