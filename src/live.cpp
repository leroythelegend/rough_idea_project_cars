#include "live.h"

#include <iostream>

#include "decodertelemetrydata.h"
#include "packet.h"

using namespace std;

namespace pcars {

void Live_Feed::live(Decoder * decoder) const
{
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		cout << "Brake " << tdecoder->brake() << endl;
	}
}

void Live_Feed_V2::live(Decoder * decoder) const
{
	Packet * packet = dynamic_cast<Packet *>(decoder);

	if (packet) {
		cout << "Brake " << packet->telemetry_data().brake() << endl;
	}
}

void Live_Feed_V2::live(Data * data) const
{
	cout << "Brake " << data->car_states()->brake() << endl;
}



}



