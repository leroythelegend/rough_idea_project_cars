# Rough Idea Project Cars

## Description

A set of cpp classes for capturing Project Cars Version 1 UDP Format.

## TODO

* Improve all current content
* Add roll your own live feed
* Add how the classes are structured
* Maybe add about how html pages work i.e. creating track data
* Version two format

## Contents
* [Introduction](#T-Introduction)
* [Install Binarys](#T-Installation)
* [Roll Your Own Post Lap](#T-post_lap)
* [Build Library](#T-Build)

## <a name="T-Introduction"></a>Introduction

A set of classes that can be used to roll your own Project Cars UDP Telemetry application. 

This project is in three parts: 
* Demo binarys ( [Install Binarys](#T-Installation) )
* Create your own Post lap processing and live telemetry 
* Create your own native application.
  
## <a name="T-Installation"></a>Install Binarys

### Capture Lap Data Demo
Capture lap data creates a lap_data.json file with all the previous laps data.
You can either write your on html file to view the json in a browser or use track_9.html,
however there is only currenlty three race lines recorded zolder, dubai club and oulton park island. 
TODO add instructions on creating more track data.

#### OSX
* cd capture_lap_data
  * ```# cd ./bin/capture_lap_data```
* Export DYLD_LIBRARY_PATH to ./lib
  * ```# export DYLD_LIBRARY_PATH=../../lib```
* Run pcars
  * ```# ./pcars```
  
* To capture post lap data you need to be doing practice i.e. not warmup, qualy or race.
* Recording starts once you begin a full lap, however it will not be recorded until you finish that lap.
* There should be a lap_data.json file which you can has the results of all your laps.
* You can use track_9.html in a browser or write your own javascript.( [track_9 screen shot](img/track_9.png) )

* To see live feed you need to be doing either race or qualy. 
* Currently the live feed only uses std out to show braking as a demo.
* You can edit live.cpp Live_Feed::live() to display more live telemetry. 
* See decodertelemetrydata.h for available telemetery interface. (rebuild [Build Library](#T-Build))

## <a name="T-post_lap"></a>Roll Your Own Post Lap
Currently I have written two Post Lap Processes (process.h), both create json files one for capturing telemetry (Process_Lap) to be used with track_9.html and the other for captureing track data (Process_Track), which I use with track_map.html to create track data for track_9.html.  

I then pass one of these Process objects to Capture_Telemetry's constructor (capturetelemetry.h).

You can dervie a new Process class that can then be used with Capture_Telemetery to create your own post lap processing.

## <a name="T-Build"></a>Build Library
#### OSX
##### Library
* Download.
* Copy to your working directory
* Open a terminal
* cd to src directory. 
  * ```# cd ./src```
* Run "make install"
  * ```# make install```
* Run "make"
  * ```# make```
* To clean the build run "make clean"
  * ```# make clean```
* For debug edit the make file e.g. add -g to compiler and link flags (there are commented out flags showing debug)
##### Executable
* cd ./bin/capture_lap_data
  * ```# cd ./bin/capture_lap_data```
* Edit main.cpp if necessary 
* Run "make"
  * ```# make```
