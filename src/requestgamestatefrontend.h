#ifndef PCARS_GAME_STATE_FRONT_END_H_
#define PCARS_GAME_STATE_FRONT_END_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Game_State_Front_End : public Request {
public:
	Request_Game_State_Front_End(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Game_State_Front_End() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;

};

}

#endif

