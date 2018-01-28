# Rough Idea PCars

## Description

A set of cpp classes for capturing Project Cars UDP telemetry.

## Contents
* [Introduction](#T-Introduction)
* [Build Library](#T-Build)
* [Install Binarys](#T-Installation)

## <a name="T-Introduction"></a>Introduction

A set of classes that can be used to roll your own UDP capture telemetry application. 

This is project is broken up into three parts: 
* Demo binarys ( [Install Binarys](#T-Installation) )
* Post lap processing and live telemetry 
* Create your own native application.

## <a name="T-Build"></a>Build Library
#### OSX
* This is only a local install i.e. download to a directory in your home directory.
* Open a terminal
* cd to src directory. 
  * ```# cd ./src```
* Run "make install"
  * ```# make install```
* Run "make"
  * ```# make```
  
## <a name="T-Installation"></a>Install Binarys

### Capture Lap Data Demo
Capture lap data creates a lap_data.json file with all the previous laps data.
You can either write your on html file to view the json in a browser or use track_9.html,
however there is only currenlty three race lines recorded zolder, dubai club and oulton park island.
#### OSX
* Make sure you have built the library as described in [Build Library](#T-Build)
* cd capture_lap_data
  * ```# cd ./bin/capture_lap_data```
* Run "make"
  * ```# make```
* Export DYLD_LIBRARY_PATH to ./lib
  * ```# export DYLD_LIBRARY_PATH=/home/your_home/your_pcars_dir_path/lib```
* Run pcars
  * ```# ./pcars```
* Open track_9.html in a browser
