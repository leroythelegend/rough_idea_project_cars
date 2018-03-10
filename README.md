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

Javascript developers can write their own web app to display the json file.

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
* May get a pop up asking to allow this app to read from a network port, press Allow. (Don't leave the app runnning because this leaves the port open, to close the exe press "control-c" e.g. control button and the letter c at the sametime).
* Do some practice laps.

Outlap in practice is not recorded so you must do at least one full lap. Recording happens while you are driving but actually writing to the json file does not happen until the lap is finished. You will see output "Recording Finished #" when that lap has been added to the json file. Open track_9.html in safari or firefox (browser).

* Create your own display using javascript to read the lap_data.json file.

## <a name="T-Part2"></a>Part 2 Roll Your Own Live feed

### Prerequisites

You need command line tools, go to apple developer for instructions on installing these for OSX. 

You will need some VI skills here to follow the tute, VI is just an editor so you can follow along in any editor (except word) or just use xcode to edit the files and use the terminal to build the applicaiton or if you are an xcode guru you know what to do ;-) . 

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
* Open the implementation file datacarstateformat1.cpp. NOTE there are some hard coded values these are only for the Format 2 Pakcets. You can see in this snippet that the tyre_temp_left is a Format 2 only data where tyre_internal_air_temp is for Format 1.
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
* Now open live.cpp
```
Your_User$ vi ./live.cpp
```
```
 12 void Live_Feed::live(std::shared_ptr<Data> data) const
 13 {
 14         cout << "Brake " << data->car_states()->brake() << endl;
 15 }
```
 * Ok so what I'm going to demonstrate is how you can capture the tyre temp and tread temp during qualifing, so you know when your tyres are up to temp for that one hot lap.
 
 * To Be Continued, have to go do some programming for money instead. :-(
 
