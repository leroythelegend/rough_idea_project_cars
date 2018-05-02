# Rough Idea Project Cars

## Description

A set of c++ classes for capturing Project Car's Version 1 and Version 2 UDP Telemetry.

## Contents

* [Version 1 and 2 Tutorial](#T-Tutorial)

## <a name="T-Tutorial"></a>Tutorial

### <a name="T-Tutorial"></a> Version 1 UDP Format

* [Part 1](#T-Part1)  Running Demo Executable
* [Part 2](#T-Part2)  Roll Your Own Live Feed
* [Part 3](#T-Part3)  Roll Your Post Lap Process
* [Part 3](#T-Part4)  Roll Your Decision Tree (WIP)

## <a name="T-Part1"></a>Part 1  Running Demo Executable

The demo application writes the post lap telemetry to a json file during practice and can be viewed using track_9.html.

JavaScript developers can write their own web app to display the json file.

I only have four track files at the moment oulton park island, dubai club, zolder and sporstland SUGO.

### Prerequisites

Project Cars 2 or 1 running on your console and UDP in options set to "UDP Protocol Version" "Project CARS 1" or "Project CARS 2". 

Experiment with the packet frequency for the right value for your system.

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
* Change Directory to capture_lap_data for version 1 or capture_lap_data_v2 for version 2.
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

Out lap in practice is not recorded so you must do at least one full lap. The recording happens while you are driving but actually writing to the json file does not happen until the lap is finished. 

You will see output "Recording Finished #" when that lap has been added to the json file. 

Open track_9.html in safari or Firefox (browser).

![alt text](https://github.com/leroythelegend/rough_idea_project_cars/blob/master/img/track_9.png)

## <a name="T-Part2"></a>Part 2 Roll Your Own Live feed

### Prerequisites

Do the first tute.

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
* Open dataformat1.h for version 1 or dataformat2.h for version 2 in an editor. Note the interface for both versions is the same however if the telemetry is not supported it's implementation returns 0.
```
Your_User$ vi ./dataformat1.h
```
* This is the object for all the "Project Cars 2 and 1" Data Packets.
```
class Data_Format_1 : public Data {
public:
         Data_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
         virtual ~Data_Format_1() {}
 
         Data_Car_State * car_states() const override;
         Data_Game_State * game_states() const override;
         Data_Input_State * input_states() const override;
         Data_Velocity_State * velocity_states() const override;
         Data_Damage_State * damage_states() const override;
         Data_Control_State * control_states() const override;
         Data_Track_State * track_states() const override;
         Data_Participants * participants() const override;
         Data_Participants_Info * participants_info() const override;
         Data_Participants_Stats * participants_stats() const override;
         Data_Split_Times * split_times() const override;
         Data_Times * times() const override;
```
* Now for this tutorial we will be using the Data_Car_State. Open datacarstateformat1.h
```
Your_User$ vi ./datacarstateformat1.h
```
```
class Data_Car_State_Format_1 : public Data_Car_State {
public:
        Data_Car_State_Format_1(std::shared_ptr<Decoder_Telemetry_Data>);
        virtual ~Data_Car_State_Format_1() {}

        unsigned int car_flags() const override;
        int oil_temp_celsius() const override;
        unsigned int oil_pressure_kpa() const override;
        int water_temp_celsius() const override;
        unsigned int water_pressure_kpa() const override;
        unsigned int fuel_pressure_kpa() const override;
        unsigned int fuel_capacity() const override;
        unsigned int brake() const override;
        unsigned int throttle() const override;
        unsigned int clutch() const override;
        float fuel_level() const override;
        float speed() const override;
        unsigned int rpm() const override;
        unsigned int max_rpm() const override;
        int steering() const override;
        unsigned int gears() const override;
        unsigned int gear() const override;
        unsigned int boost_amount() const override;
        unsigned int crash_state() const override;
        float odometer_km() const override;
        Vector_UInt tyre_flags() const override;
        Vector_UInt terrain() const override;
        Vector_Float tyre_y() const override;
...
```
* Open the implementation file datacarstateformat1.cpp or atacarstateformat2.cpp. NOTE again there are some hard coded values, these are for unsupported telemetry across the Format Packets. You can see in this snippet that the tyre_temp_left is a Format 2 only data where tyre_internal_air_temp is for Format 1.
```
 
 Vector_UInt Data_Car_State_Format_1::tyre_internal_air_temp() const {
         return telemetry_data_->tyre_internal_air_temp();
 }
 
 Vector_UInt Data_Car_State_Format_1::tyre_temp_left() const {
         Vector_UInt vu;
         return vu;
 }
```
* Now open live.h
```
Your_User$ vi ./live.h
```
* Ok so what I'm going to demonstrate is how you can capture the tyre temp and tread temp during qualifying, so you know when your tyres are up to temp for that one hot lap.
* Add the include vector with the rest of the live.h includes. 
```
4 #include <vector>
```
* We want to derive a new Live_Temp class from the Live type base class, add this code to live.h between the pcars namespace.
```
 class Live_Temp : public Live {
 public:
         enum class TEMP {
                 COLD = 0,
                 GOOD,
                 HOT,
                 UNKNOWN
         };
 
         enum class TREAD {
                 GOOD = 0,
                 HOT,
                 UNKNOWN
         };
 
         using Temp = unsigned int;
         using Temp_Vec = std::vector<TEMP>;
         using Tread_Vec = std::vector<TREAD>;
 
         Live_Temp();
         virtual ~Live_Temp() {}
 
         void live(std::shared_ptr<Data>) override;
 private:
         Temp min_tyre_temp_;
         Temp max_tyre_temp_;
         Temp max_tread_temp_;
 
         Temp_Vec temp_;
         Tread_Vec tread_;
 
         std::string fl_temp;
         std::string fr_temp;
         std::string rl_temp;
         std::string rr_temp;
 
         std::string fl_tread;
         std::string fr_tread;
         std::string rl_tread;
         std::string rr_tread;
  };
```
* Add this to the implementation live.cpp between the pcars namespace. (This could be done better but for this tute I think it is fine)
```
 
 Live_Temp::Live_Temp()
         : min_tyre_temp_{70},
           max_tyre_temp_{80},
           max_tread_temp_{360},
           temp_{TEMP::UNKNOWN, TEMP::UNKNOWN, TEMP::UNKNOWN, TEMP::UNKNOWN},
           tread_{TREAD::UNKNOWN, TREAD::UNKNOWN, TREAD::UNKNOWN, TREAD::UNKNOWN}
 {
 }
 
 void Live_Temp::live(std::shared_ptr<Data> data)
 {
 
          bool changed = false;
  
          if (min_tyre_temp_ > data->car_states()->tyre_temp().at(0) &&
              temp_.at(0) != TEMP::COLD) {
                  temp_.at(0) = TEMP::COLD;
                  changed = true;
                  fl_temp = "FL COLD ";
          }
          if (max_tyre_temp_ < data->car_states()->tyre_temp().at(0) &&
              temp_.at(0) != TEMP::HOT) {
                  temp_.at(0) = TEMP::HOT;
                  changed = true;
                  fl_temp = "FL HOT ";
          }
          if (min_tyre_temp_ < data->car_states()->tyre_temp().at(0) &&
              max_tyre_temp_ > data->car_states()->tyre_temp().at(0) &&
             temp_.at(0) != TEMP::GOOD) {
                 temp_.at(0) = TEMP::GOOD;
                 changed = true;
                 fl_temp = "FL GO-GO ";
         }
 
         if (min_tyre_temp_ > data->car_states()->tyre_temp().at(1) &&
             temp_.at(1) != TEMP::COLD) {
                 temp_.at(1) = TEMP::COLD;
                 changed = true;
                 fr_temp = "FR COLD ";
         }
         if (max_tyre_temp_ < data->car_states()->tyre_temp().at(1) &&
             temp_.at(1) != TEMP::HOT) {
                 temp_.at(1) = TEMP::HOT;
                 changed = true;
                 fr_temp = "FR HOT ";
         }
         if (min_tyre_temp_ < data->car_states()->tyre_temp().at(1) &&
             max_tyre_temp_ > data->car_states()->tyre_temp().at(1) &&
             temp_.at(1) != TEMP::GOOD) {
                 temp_.at(1) = TEMP::GOOD;
                 changed = true;
                 fr_temp = "FR GO-GO ";
         }
 
         if (min_tyre_temp_ > data->car_states()->tyre_temp().at(2) &&
             temp_.at(2) != TEMP::COLD) {
                 temp_.at(2) = TEMP::COLD;
                 changed = true;
                 rl_temp = "RL COLD ";
         }
         if (max_tyre_temp_ < data->car_states()->tyre_temp().at(2) &&
             temp_.at(2) != TEMP::HOT) {
                 temp_.at(2) = TEMP::HOT;
                 changed = true;
                 rl_temp = "RL HOT ";
         }
         if (min_tyre_temp_ < data->car_states()->tyre_temp().at(2) &&
             max_tyre_temp_ > data->car_states()->tyre_temp().at(2) &&
             temp_.at(2) != TEMP::GOOD) {
                 temp_.at(2) = TEMP::GOOD;
                 changed = true;
                 rl_temp = "RL GO-GO ";
         }
 
         if (min_tyre_temp_ > data->car_states()->tyre_temp().at(3) &&
             temp_.at(3) != TEMP::COLD) {
                 temp_.at(3) = TEMP::COLD;
                 changed = true;
                 rr_temp = "RR COLD ";
         }
         if (max_tyre_temp_ < data->car_states()->tyre_temp().at(3) &&
             temp_.at(3) != TEMP::HOT) {
                 temp_.at(3) = TEMP::HOT;
                 changed = true;
                 rr_temp = "RR HOT ";
         }
         if (min_tyre_temp_ < data->car_states()->tyre_temp().at(3) &&
             max_tyre_temp_ > data->car_states()->tyre_temp().at(3) &&
             temp_.at(3) != TEMP::GOOD) {
                 temp_.at(3) = TEMP::GOOD;
                 changed = true;
                 rr_temp = "RR GO-GO ";
         }
 
 
         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(0) &&
             tread_.at(0) != TREAD::GOOD) {
                 tread_.at(0) = TREAD::GOOD;
                 changed = true;
                 fl_tread = "FL GOOD ";
         }
         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(0) &&
             tread_.at(0) != TREAD::HOT) {
                 tread_.at(0) = TREAD::HOT;
                 changed = true;
                 fl_tread = "FL HOT ";
         }
 
         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(1) &&
             tread_.at(1) != TREAD::GOOD) {
                 tread_.at(1) = TREAD::GOOD;
                 changed = true;
                 fr_tread = "FR GOOD ";
         }
         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(1) &&
             tread_.at(1) != TREAD::HOT) {
                 tread_.at(1) = TREAD::HOT;
                 changed = true;
                 fr_tread = "FR HOT ";
         }
 
         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(2) &&
             tread_.at(2) != TREAD::GOOD) {
                 tread_.at(2) = TREAD::GOOD;
                 changed = true;
                 rl_tread = "FL GOOD ";
         }
         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(2) &&
             tread_.at(2) != TREAD::HOT) {
                 tread_.at(2) = TREAD::HOT;
                 changed = true;
                 rl_tread = "RL HOT ";
         }
 
         if (max_tread_temp_ > data->car_states()->tyre_tread_temp().at(3) &&
             tread_.at(3) != TREAD::GOOD) {
                 tread_.at(3) = TREAD::GOOD;
                 changed = true;
                 rr_tread = "RR GOOD ";
         }
         if (max_tread_temp_ < data->car_states()->tyre_tread_temp().at(3) &&
             tread_.at(3) != TREAD::HOT) {
                 tread_.at(3) = TREAD::HOT;
                 changed = true;
                 rr_tread = "RR HOT ";
         }
 
         if (changed) {
                 cout << "TYRE TEMP" << endl;
                 cout << fl_temp << fr_temp << rl_temp << rr_temp << endl;
                 cout << "TYRE TREAD TEMP" << endl;
                 cout << fl_tread << fr_tread << rl_tread << rr_tread;
                 for (int i = 0; i < 20; ++i) {
                         cout << endl;
                 }
         }
 }
```
* in the src directory run make clean then make
```
Your_User$ make clean
rm -f ../obj/*.o *~ ../lib/librough_idea_pcars.dylib
```
```
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
  int main() {
  
          pcars::Process_Decision_Tree decision_tree;
          pcars::Process_Lap process;
          //pcars::Live_Feed live;
          pcars::Live_Temp live;
          pcars::Capture_Telemetry telemetry(&process, &live, &decision_tree);
  
          return 0;
  
  }
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

## <a name="T-Part3"></a>Part 3 Roll Your Own Post Lap Process

### Prerequisites

Have done tute 1 and 2. 

### Tute

* I'm going to assume that you have done tute 1 and 2 and skip a lot of the basics and just get straight into adding a new process because this is very similar to extending the live class.
* Open process.h from the src directory in your editor. We want to use the Process_Track class instead of the Process_Lap. 
```
class Process_Track : public Process {
public:
        Process_Track();
        virtual ~Process_Track() {}

        void process(const Lap_Data lap_data) const override;
};
```
* We don't need to build this as I have already implemented this class, you can take a look at the implementation in process.cpp. I use this class to create my track data for track_9.html. (I need to do a lot of work to improve my JavaScript).
* Go to the bin/capture_track_data or bin/capture_track_data_v2 and open the main.cpp, I have replaced Process_Lap with Process_Track.
```
  1 #include "capturetelemetry.h"
  2 #include "process.h"
  3 #include "live.h"
  4 
  5 int main() {
  6 
  7         pcars::Process_Decision_Tree decision_tree;
  8         pcars::Process_Track track;  <-------------- HERE
  9         pcars::Live_Feed live;
 10         pcars::Capture_Telemetry telemetry(&track, &live, &decision_tree);
 11 
 12         return 0;
 13 
 14 }
```
* Set up your Library Path as in the previous tutes and run pcars. When I capture a lap I have the race line switched on and I do 1 lap on the outside, one on the inside and one on the race line.  Then I open this up in track_map.html and zoom into the track by changing the JavaScript and then record all the start, turn-in, apexes, exit and finish distances for each corner and some zoom to see the corners and the track and add this data to track_9.html. Finally do a lap using the capture_lap_data exe breaking on the turn-in, apexes and exit to fine tune track_9.html. It is a lot of work and needs to be improved hence this is why I only have 3 tracks.

## <a name="T-Part4"></a>Part 4  Roll Your Own Decision Tree

This is still work in progress so far so good working as expected added some more absolutes and decisions.

The idea is that you think of some setup question you might have for example "Does the top gear hit the rev limiter" and build up the decision tree with this question. If I have this right there will be one decision tree answering multiple questions.

Ok so first think, given these absolutes what desiscion can i conclude. Using the previous example "the car absolutly must be on the road, absolutly must be in top gear and was the max rpm's reached? if true max rpms hit else false not hit" 

Take a look at decision.h and decision.cpp

So I derive two classes from Absolute, Absolute_On_Road and Absolute_Top_Gear then create a multi inheritance class from Decision and Result, Decision_MAX_RPM and finally I pass my Conclusion type Conclusion_Cout to Decision_MAX_RPM as well. The flow should go like this 

Are all four tyres on the road? ---> True: Are we in top Gear? --> True: Did the RPMS reach Max RPMS? --> Print conclusion and True else False.

Conclusion is encapsulated in the final decision so this can change for different output i.e. json or to a file.

Creating the decision tree, wow I actually wrote some comments.

```
 60 class Process_Decision_Tree : public Process_Session {
 61 public:
 62         using Decisions = std::vector<std::shared_ptr<Decision> >; 
 63         using Results = std::vector<std::shared_ptr<Result> >; 
 64 
 65         Process_Decision_Tree();
 66         virtual ~Process_Decision_Tree() {}
 67 
 68         void capture_session(const Lap_Data&) override;
 69         void process_session() override;
 70 
 71 private:
 72         Decisions decisions_;
 73         Results results_;
 74 
 75         Lap_Data lap_data_;
 76 };
 
241 Process_Decision_Tree::Process_Decision_Tree()
242 {
243         // Decision > On_Road
244         // Decision > Tyre_Temp
245         std::shared_ptr<Decision> on_road = std::make_shared<Absolute_On_Road>();
246         std::shared_ptr<Decision_MAX_Tyre_Temp> tyre_temp =  std::make_shared<Decision_MAX_Tyre_Temp>(std::make_shared<Conclusion_Cout>("FL MAX Tyre Temp ",
247           "FR MAX Tyre Temp ",
248           "RL MAX Tyre Temp ",
249           "RR MAX Tyre Temp "));
250         decisions_.push_back(on_road);
251         decisions_.push_back(tyre_temp);
252         // Decision > On_Road T Top_Gear
253         std::shared_ptr<Decision> top_gear = std::make_shared<Absolute_Top_Gear>();
254         decisions_.at(0)->if_true(top_gear);
255         // Decision > On_Road T Top_Gear T MAX_RPM
256         // Decision > On_Road T Top_Gear T RPM_GT_80
257         std::shared_ptr<Decision_MAX_RPM> max_rpm = std::make_shared<Decision_MAX_RPM>(std::make_shared<Conclusion_Cout>("Top gear hit max rpms "));
258         std::shared_ptr<Decision_RPM_GT_80_Percent> rpm_gt_80 = std::make_shared<Decision_RPM_GT_80_Percent>(std::make_shared<Conclusion_Cout>("Top gear rpm greater than 80% "));
259         top_gear->if_true(max_rpm);
260         top_gear->if_true(rpm_gt_80);
261 
262         // Results
263         results_.push_back(max_rpm);
264         results_.push_back(rpm_gt_80);
265         results_.push_back(tyre_temp);
266 }
```

