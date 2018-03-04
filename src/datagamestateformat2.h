#ifndef PCARS_DATA_GAME_STATE_FORMAT_2_H_
#define PCARS_DATA_GAME_STATE_FORMAT_2_H_

#include "datagamestate.h"
#include "packet.h"

namespace pcars {

class Data_Game_State_Format_2 : public Data_Game_State {
public:
	Data_Game_State_Format_2(std::shared_ptr<Packet>);
	virtual ~Data_Game_State_Format_2() {}

	unsigned int session_state() const override;
	unsigned int game_state() const override;
	unsigned int race_state_flags() const override;
	unsigned int pit_mode() const override;
	
private:
	std::shared_ptr<Packet> packet_;
};

}

#endif

