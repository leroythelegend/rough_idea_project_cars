#include "dataparticipantsformat1.h"

namespace pcars {

Data_Participants_Format_1::Data_Participants_Format_1() {}

std::string Data_Participants_Format_1::name(Participant) const {
	return "";
}

unsigned int Data_Participants_Format_1::nationality(Participant) const {
	return 0;
}

unsigned int Data_Participants_Format_1::index(Participant) const {
	return 0;
}

}

