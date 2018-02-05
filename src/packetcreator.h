#ifndef PCARS_PACKET_CREATOR_H_
#define PCARS_PACKET_CREATOR_H_

#include "consts.h"

namespace pcars {

class Packet_Creator {
public:
	Packet_Creator();
	virtual ~Packet_Creator() {}

private:
	Packet_Base base_;
	Packet_Game_State game_state_; 
	Packet_Telemetry_Data telemetry_data_;
};

}

#endif

