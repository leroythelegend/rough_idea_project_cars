#ifndef PCARS_LIVE_DATA_H_
#define PCARS_LIVE_DATA_H_

#include "decoder.h"

namespace pcars { 

class Live {
public:
	virtual ~Live() {}

	virtual void live(Decoder *) const = 0;
};

class Live_Feed : public Live {
public:
	virtual ~Live_Feed() {}

	virtual void live(Decoder *) const;
};

class Live_Feed_V2 : public Live {
public:
	virtual ~Live_Feed_V2() {}

	virtual void live(Decoder *) const;
};


}

#endif

