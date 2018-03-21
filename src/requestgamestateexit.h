#ifndef PCARS_REQUEST_GAME_STATE_EXIT_H_
#define PCARS_REQUEST_GAME_STATE_EXIT_H_

#include "request.h"

#include "recordlap.h"

namespace pcars {

class Request_Game_State_Exit : public Request {
public:
	Request_Game_State_Exit(Record_Lap * = nullptr, Request * = nullptr);
	virtual ~Request_Game_State_Exit() {}

	bool request(std::shared_ptr<Data>) override;

private:
	Record_Lap * record_;
	Request * request_;
};

}

#endif

