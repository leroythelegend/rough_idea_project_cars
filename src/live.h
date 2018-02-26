#ifndef PCARS_LIVE_DATA_H_
#define PCARS_LIVE_DATA_H_

#include "decoder.h"
#include "data.h"

namespace pcars { 

class Live {
public:
	virtual ~Live() {}

	virtual void live(Decoder *) const = 0;
	virtual void live(std::shared_ptr<Data>) const = 0;
};

class Live_Feed : public Live {
public:
	virtual ~Live_Feed() {}

	void live(Decoder *) const override;
	void live(std::shared_ptr<Data>) const override {};
};

class Live_Feed_V2 : public Live {
public:
	virtual ~Live_Feed_V2() {}

	void live(Decoder *) const override;
	void live(std::shared_ptr<Data>) const override;
};


}

#endif

