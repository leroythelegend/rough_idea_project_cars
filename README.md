# Rough Idea Project Cars

## Description

A set of c++ classes for capturing Project Car's Version 1 and Version 2 UDP Telemetry.

## Contents

* [Version 1 Tutorial](#T-Tutorial)

## <a name="T-Tutorial"></a>Tutorial

### <a name="T-Tutorial"></a> Version 1 UDP Format

* [Part 1](#T-Part1)  Running Demo Executable
* [Part 2](#T-Part2)  Roll Your Own Live Feed

## <a name="T-Part1"></a>Part 1  Running Demo Executable

The demo application writes the post lap telemetry to a json file during practice and can be viewed using track_9.html.

JavaScript developers can write their own web app to display the json file.

I only have three track files at the moment oulton park island, dubai club and zolder.

### Prerequisites

Project Cars 2 or 1 running on your console and UDP in options set to "UDP Protocol Version" "Project CARS 1". 

Note for the "UDP Frequency" my PlayStation says higher the value more packets but I think this is back to front I found lower the value more the packets. Anyway experiment with these values to get the right setting for you.

#### Tute

The demo runs in a terminal so I'm just going to use a terminal for the tutorial.

* "Download Zip" of the Repo.
* Open a Terminal
* Copy rough_idea_project_cars-master to your working directory. (if you don't have a working dir, from a terminal run "mkdir ~/your_working_dir").
```
Your_User$ cp -r ~/Downloads/rough_idea_project_cars-master ~/your_working_dir/
```
* Change Directory to ~/your_working_dir/rough_idea_project_cars-master/bin
```
Your_User$ cd ~/your_working_dir/rough_idea_project_cars-master/bin
```
* Change Directory to capture_lap_data
```
Your_User$ cd ./capture_lap_data
```
* List the contents of the directory
```
Your_User$ ls -l
total 97864
-rw-r--r--  1 Your_User  staff    248031  3 Feb 18:37 DubaiAeroDromeClub_raceline_track.json
-rw-r--r--  1 Your_User  staff       214  6 Feb 08:12 main.cpp
-rwxr-xr-x  1 Your_User  staff       449  6 Feb 08:12 makefile
-rw-r--r--  1 Your_User  staff  17027175  3 Feb 18:37 oulton_park_island.json
-rwxr-xr-x  1 Your_User  staff     11180  6 Feb 08:12 pcars
-rw-r--r--  1 Your_User  staff     29181  6 Feb 08:12 track_9.html
-rw-r--r--  1 Your_User  staff    227530  3 Feb 18:37 zolder_raceline_track.json
```
* Add rough ideas pcars library to your library path
```
Your_User$ export DYLD_LIBRARY_PATH=../../lib
```
* Now run the executable and do some PRACTICE laps on Oulton Park Island. Note I don't capture the out lap and the demo writes the previous lap to the json file so you have to complete a full lap before it will be captured.
```
Your_User$ ./pcars
```
* May get a pop up asking to allow this app to read from a network port, press Allow. (Don't leave the app running because this leaves the port open, to close the exe press "control-c" e.g. control button and the letter c at the same time).
* Do some practice laps.

Out lap in practice is not recorded so you must do at least one full lap. Recording happens while you are driving but actually writing to the json file does not happen until the lap is finished. You will see output "Recording Finished #" when that lap has been added to the json file. Open track_9.html in safari or Firefox (browser).

![alt text](https://github.com/leroythelegend/rough_idea_project_cars/blob/master/img/track_9.png)

* Create your own display using JavaScript to read the lap_data.json file.

## <a name="T-Part2"></a>Part 2 Roll Your Own Live feed

### Prerequisites

You need command line tools, go to apple developer for instructions on installing these for OSX. 

You will need some VI skills here to follow the tute, VI is just an editor so you can follow along in any editor (except word) or just use xcode to edit the files and use the terminal to build the application or if you are an xcode guru you know what to do ;-) .

WARNING if you change a header file (.h file) you should run "make clean" and "make" from in the src directory. 

#### Tute

I'm just going to use a terminal for the tutorials.

* Download the Repo.
* Open a Terminal
* Copy rough_idea_project_cars-master to your working directory. (if you don't have a working dir, from a terminal run "mkdir ~/your_working_dir").
```
Your_User$ cp -r ~/Downloads/rough_idea_project_cars-master ~/your_working_dir/
```
* Change Directory to ~/your_working_dir/rough_idea_project_cars-master/src
```
Your_User$ cd ~/your_working_dir/rough_idea_project_cars-master/src
```
* Open dataformat1.h in an editor.
```
Your_User$ vi ./dataformat1.h
```
* This is the object for all the "Project Cars 2 and 1" Data Packets.
```
 11 class Data_Format_1 : public Data {
 12 public:
 13         Data_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
 14         virtual ~Data_Format_1() {}
 15 
 16         Data_Car_State * car_states() const override;
 17         Data_Game_State * game_states() const override;
 18         Data_Input_State * input_states() const override;
 19         Data_Velocity_State * velocity_states() const override;
 20         Data_Damage_State * damage_states() const override;
 21         Data_Control_State * control_states() const override;
 22         Data_Track_State * track_states() const override;
 23         Data_Participants * participants() const override;
 24         Data_Participants_Info * participants_info() const override;
 25         Data_Participants_Stats * participants_stats() const override;
 26         Data_Split_Times * split_times() const override;
 27         Data_Times * times() const override;
```
* Now for this tutorial we will be using the Data_Car_State. Open datacarstateformat1.h
```
Your_User$ vi ./datacarstateformat1.h
```
```
 10 class Data_Car_State_Format_1 : public Data_Car_State {
 11 public:
 12         Data_Car_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
 13         virtual ~Data_Car_State_Format_1() {}
 14 
 15         unsigned int car_flags() const override;
 16         int oil_temp_celsius() const override;
 17         unsigned int oil_pressure_kpa() const override;
 18         int water_temp_celsius() const override;
 19         unsigned int water_pressure_kpa() const override;
 20         unsigned int fuel_pressure_kpa() const override;
 21         unsigned int fuel_capacity() const override;
 22         unsigned int brake() const override;
 23         unsigned int throttle() const override;
 24         unsigned int clutch() const override;
 25         float fuel_level() const override;
 26         float speed() const override;
 27         unsigned int rpm() const override;
 28         unsigned int max_rpm() const override;
 29         int steering() const override;
 30         unsigned int gears() const override;
 31         unsigned int gear() const override;
 32         unsigned int boost_amount() const override;
 33         unsigned int crash_state() const override;
 34         float odometer_km() const override;
 35         Vector_UInt tyre_flags() const override;
 36         Vector_UInt terrain() const override;
 37         Vector_Float tyre_y() const override;
...
```
* Open the implementation file datacarstateformat1.cpp. NOTE there are some hard coded values these are only for the Format 2 Packets. You can see in this snippet that the tyre_temp_left is a Format 2 only data where tyre_internal_air_temp is for Format 1.
```
147 
148 Vector_UInt Data_Car_State_Format_1::tyre_internal_air_temp() const {
149         return telemetry_data_->tyre_internal_air_temp();
150 }
151 
152 Vector_UInt Data_Car_State_Format_1::tyre_temp_left() const {
153         Vector_UInt vu;
154         return vu;
155 }
```
* Now open live.h
```
Your_User$ vi ./live.h
```
* Ok so what I'm going to demonstrate is how you can capture the tyre temp and tread temp during qualifying, so you know when your tyres are up to temp for that one hot lap.
* Add the include vector with rest of the live.h includes. 
```
4 #include <vector>
```
* We want to derive a new Live_Temp class from the Live type, add this code to live.h between the pcars namespace.
```
 45 class Live_Temp : public Live {
 46 public:
 47         enum class TEMP {
 48                 COLD = 0,
 49                 GOOD,
 50                 HOT,
 51                 UNKNOWN
 52         };
 53 
 54         enum class TREAD {
 55                 GOOD = 0,
 56                 HOT,
 57                 UNKNOWN
 58         };
 59 
 60         using Temp = unsigned int;
 61         using Temp_Vec = std::vector<TEMP>;
 62         using Tread_Vec = std::vector<TREAD>;
 63 
 64         Live_Temp();
 65         virtual ~Live_Temp() {}
 66 
 67         void live(std::shared_ptr<Data>) override;
 68 private:
 69         Temp min_tyre_temp_;
 70         Temp max_tyre_temp_;
 71         Temp max_tread_temp_;
 72 
 73         Temp_Vec temp_;
 74         Tread_Vec tread_;
 75 
 76         std::string fl_temp;
 77         std::string fr_temp;
 78         std::string rl_temp;
 79         std::string rr_temp;
 80 
 81         std::string fl_tread;
 82         std::string fr_tread;
 83         std::string rl_tread;
 84         std::string rr_tread;
 85 };
```
* Add this to the implementation live.cpp between the pcars namespace. (This could be done better but for this tute I think it is fine)
```
 62 
 63 Live_Temp::Live_Temp()
 64         : min_tyre_temp_{70},
 65           max_tyre_temp_{80},
 66           max_tread_temp_{360},
 67           temp_{TEMP::UNKNOWN, TEMP::UNKNOWN, TEMP::UNKNOWN, TEMP::UNKNOWN},
 68           tread_{TREAD::UNKNOWN, TREAD::UNKNOWN, TREAD::UNKNOWN, TREAD::UNKNOWN}
 69 {
 70 }
 71 
 72 void Live_Temp::live(std::shared_ptr<Data> data)
 73 {
 74 
 75         bool changed = false;
 76 
 77         if (min_tyre_temp_ > data->car_states()->tyre_temp().at(0) &&
 78             temp_.at(0) != TEMP::COLD) {
 79                 temp_.at(0) = TEMP::COLD;
 80                 changed = true;
 81                 fl_temp = "FL COLD ";
 82         }
 83         if (max_tyre_temp_ < data->car_states()->tyre_temp().at(0) &&
 84             temp_.at(0) != TEMP::HOT) {
 85                 temp_.at(0) = TEMP::HOT;
 86                 changed = true;
 87                 fl_temp = "FL HOT ";
 88         }
 89         if (min_tyre_temp_ < data->car_states()->tyre_temp().at(0) &&
 90             max_tyre_temp_ > data->car_states()->tyre_temp().at(0) &&
 91             temp_.at(0) != TEMP::GOOD) {
 92                 temp_.at(0) = TEMP::GOOD;
 93                 changed = true;
 94                 fl_temp = "FL GO-GO ";
 95         }
 96 
 97         if (min_tyre_temp_ > data->car_states()->tyre_temp().at(1) &&
 98             temp_.at(1) != TEMP::COLD) {
 99                 temp_.at(1) = TEMP::COLD;
100                 changed = true;
101                 fr_temp = "FR COLD ";
102         }
103         if (max_tyre_temp_ < data->car_states()->tyre_temp().at(1) &&
104             temp_.at(1) != TEMP::HOT) {
105                 temp_.at(1) = TEMP::HOT;
106                 changed = true;
107                 fr_temp = "FR HOT ";
108         }
109         if (min_tyre_temp_ < data->car_states()->tyre_temp().at(1) &&
110             max_tyre_temp_ > data->car_states()->tyre_temp().at(1) &&
111             temp_.at(1) != TEMP::GOOD) {
112                 temp_.at(1) = TEMP::GOOD;
113                 changed = true;
114                 fr_temp = "FR GO-GO ";
115         }
116 
117         if (min_tyre_temp_ > data->car_states()->tyre_temp().at(2) &&
118             temp_.at(2) != TEMP::COLD) {
119                 temp_.at(2) = TEMP::COLD;
120                 changed = true;
121                 rl_temp = "RL COLD ";
122         }
123         if (max_tyre_temp_ < data->car_states()->tyre_temp().at(2) &&
124             temp_.at(2) != TEMP::HOT) {
125                 temp_.at(2) = TEMP::HOT;
126                 changed = true;
127                 rl_temp = "RL HOT ";
128         }
129         if (min_tyre_temp_ < data->car_states()->tyre_temp().at(2) &&
130             max_tyre_temp_ > data->car_states()->tyre_temp().at(2) &&
131             temp_.at(2) != TEMP::GOOD) {
132                 temp_.at(2) = TEMP::GOOD;
133                 changed = true;
134                 rl_temp = "RL GO-GO ";
135         }
136 
137         if (min_tyre_temp_ > data->car_states()->tyre_temp().at(3) &&
138             temp_.at(3) != TEMP::COLD) {
139                 temp_.at(3) = TEMP::COLD;
140                 changed = true;
141                 rr_temp = "RR COLD ";
142         }
143         if (max_tyre_temp_ < data->car_states()->tyre_temp().at(3) &&
144             temp_.at(3) != TEMP::HOT) {
145                 temp_.at(3) = TEMP::HOT;
146                 changed = true;
147                 rr_temp = "RR HOT ";
148         }
149         if (min_tyre_temp_ < data->car_states()->tyre_temp().at(3) &&
150             max_tyre_temp_ > data->car_states()->tyre_temp().at(3) &&
151             temp_.at(3) != TEMP::GOOD) {
152                 temp_.at(3) = TEMP::GOOD;
153                 changed = true;
154                 rr_temp = "RR GO-GO ";
155         }
156 
157 
158         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(0) &&
159             tread_.at(0) != TREAD::GOOD) {
160                 tread_.at(0) = TREAD::GOOD;
161                 changed = true;
162                 fl_tread = "FL GOOD ";
163         }
164         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(0) &&
165             tread_.at(0) != TREAD::HOT) {
166                 tread_.at(0) = TREAD::HOT;
167                 changed = true;
168                 fl_tread = "FL HOT ";
169         }
170 
171         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(1) &&
172             tread_.at(1) != TREAD::GOOD) {
173                 tread_.at(1) = TREAD::GOOD;
174                 changed = true;
175                 fr_tread = "FR GOOD ";
176         }
177         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(1) &&
178             tread_.at(1) != TREAD::HOT) {
179                 tread_.at(1) = TREAD::HOT;
180                 changed = true;
181                 fr_tread = "FR HOT ";
182         }
183 
184         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(2) &&
185             tread_.at(2) != TREAD::GOOD) {
186                 tread_.at(2) = TREAD::GOOD;
187                 changed = true;
188                 rl_tread = "FL GOOD ";
189         }
190         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(2) &&
191             tread_.at(2) != TREAD::HOT) {
192                 tread_.at(2) = TREAD::HOT;
193                 changed = true;
194                 rl_tread = "RL HOT ";
195         }
196 
197         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(3) &&
198             tread_.at(3) != TREAD::GOOD) {
199                 tread_.at(3) = TREAD::GOOD;
200                 changed = true;
201                 rr_tread = "RR GOOD ";
202         }
203         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(3) &&
204             tread_.at(3) != TREAD::HOT) {
205                 tread_.at(3) = TREAD::HOT;
206                 changed = true;
207                 rr_tread = "RR HOT ";
208         }
209 
210         if (changed) {
211                 cout << "TYRE TEMP" << endl;
212                 cout << fl_temp << fr_temp << rl_temp << rr_temp << endl;
213                 cout << "TYRE TREAD TEMP" << endl;
214                 cout << fl_tread << fr_tread << rl_tread << rr_tread;
215                 for (int i = 0; i < 20; ++i) {
216                         cout << endl;
217                 }
218         }
219 }
```
* in the src directory run make clean then make
```
Your_User$ make clean
rm -f ../obj/*.o *~ ../lib/librough_idea_pcars.dylib
Your_User$ make
g++ -m64 -std=c++14 -Wall -Wextra  -I./ -c capturetelemetry.cpp  -o ../obj/capturetelemetry.o
g++ -m64 -std=c++14 -Wall -Wextra  -I./ -c capturetelemetryv2.cpp  -o ../obj/capturetelemetryv2.o
...
```
* Now we need to add the class to the capture_lap_data. Change directory to rough_idea_project_cars-master/bin/capture_lap_data
```
Your_User$ ~/your_working_dir/rough_idea_project_cars-master/bin/capture_lap_data
```
* Open main.cpp and change Live_Feed to Live_Temp
```
  5 int main() {
  6 
  7         pcars::Process_Lap process;
  8         //pcars::Live_Feed live;
  9         pcars::Live_Temp live;
 10         pcars::Capture_Telemetry telemetry(&process, &live);
 11 
 12         return 0;
 13 
 14 }
```
* Run make
```
Your_User$ make
```
* Set the library path.
```
Your_User$ export DYLD_LIBRARY_PATH=../../lib
```
* Run pcars and do some qualy laps. 
```
Your_User$ ./pcars
Started
```
* You may have noticed that the out lap does not show the tyre state, which is not realy what we want. We want to see the tyre state coming into the first lap. The API controls the state of the app using the Chain of Responsibility Design Pattern which allows a request to run down a chain and find its response. The set of request classes implement this responsibility open requestsessionstatequalify.h. First we need to include the requestracestatenotstarted.h header file to the qualy header file. So cd back to the src directory.
* Open requestsessionstatequalify.h and add the the include file for the requestracestatenotstarted.h.
```
#include "requestracestatenotstarted.h"
```
* Now add a not started member to the qualy class.
```
 11 class Request_Session_State_Qualify : public Request {
 12 public:
 13         Request_Session_State_Qualify(Record_Lap *, Request * request = nullptr);
 14         virtual ~Request_Session_State_Qualify() {}
 15 
 16         bool request(std::shared_ptr<Data>) override;
 17 
 18 private:
 19         Request * request_;
 20 
 21         Request_Race_State_Not_Started notstarted_; <------- HERE
 22         Request_Race_State_Racing racing_;
 23 
 24         Request_Session_State_Qualify(const Request_Session_State_Qualify&) = delete;
 25         Request_Session_State_Qualify& operator=(const Request_Session_State_Qualify&) = delete;
 26 };
```
* Now open the implementation file requestsessionstatequalify.cpp and add the not started object to the request chain in the constructors initialisation list. 
```
  7 Request_Session_State_Qualify::Request_Session_State_Qualify(Record_Lap * record, Request * request)
  8         : request_{request},
  9           notstarted_{record},
 10           racing_{record,&notstarted_} {}
```
* What is happening is the chain first checks not start and if we are in a not started state we will run the recording from there else we move down the chain to racing and see if we are racing.  This class allows us to collect data at all different application states.
* Make clean and Make again
```
Your_User$ make clean
rm -f ../obj/*.o *~ ../lib/librough_idea_pcars.dylib
Your_User$ make
g++ -m64 -std=c++14 -Wall -Wextra  -I./ -c capturetelemetry.cpp  -o ../obj/capturetelemetry.o
g++ -m64 -std=c++14 -Wall -Wextra  -I./ -c capturetelemetryv2.cpp  -o ../obj/capturetelemetryv2.o
...
```
* Go back to the bin directory and start pcars and do some laps you don't need to rebuild, pcars will pick up the changes from the shared library.  
* My idea of the live type was so that GUI developers can use the live feed to create their own unique pcars displays.
* To Be Continued, next will be a tute on the post lap process.
 

