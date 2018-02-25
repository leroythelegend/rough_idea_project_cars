#ifndef PCARS_DATA_H_
#define PCARS_DATA_H_

#include "datacarstate.h"
#include "datagamestate.h"
#include "datainputstate.h"
#include "datavelocitystate.h"
#include "datadamagestate.h"
#include "datacontrolstate.h"
#include "datatrackstate.h"
#include "dataparticipants.h"
#include "dataparticipantsinfo.h"
#include "datasplittimes.h"
#include "datatimes.h"
#include "dataparticipantsstats.h"

namespace pcars {

class Data {
public:
	virtual ~Data() {}

	virtual	Data_Car_State * car_states() const = 0;	
	virtual Data_Game_State * game_states() const = 0;
	virtual Data_Input_State * input_states() const = 0;
	virtual Data_Velocity_State * velocity_states() const = 0;
	virtual Data_Damage_State * damage_states() const = 0;
	virtual Data_Control_State * control_states() const = 0;
	virtual Data_Track_State * track_states() const = 0;
	virtual Data_Participants * participants() const = 0;
	virtual Data_Participants_Info * participants_info() const = 0;
	virtual Data_Participants_Stats * participants_stats() const = 0;
	virtual Data_Split_Times * split_times() const = 0;
	virtual Data_Times * times() const = 0;
};

}

#endif

