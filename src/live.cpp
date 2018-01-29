#include "live.h"

#include <iostream>

#include "decodertelemetrydata.h"

using namespace std;

namespace pcars {

void Live_Feed::live(Decoder * decoder) const
{
	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {
		cout << "Brake " << tdecoder->brake() << endl;
	}
}

}



