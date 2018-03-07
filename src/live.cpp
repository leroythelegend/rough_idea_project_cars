#include "live.h"

#include <iostream>

#include "decodertelemetrydata.h"
#include "packet.h"

using namespace std;

namespace pcars {

void Live_Feed::live(std::shared_ptr<Data> data) const
{
	cout << "Brake " << data->car_states()->brake() << endl;
}



}



