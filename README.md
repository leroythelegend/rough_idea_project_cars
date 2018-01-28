# Rough Idea PCars

## Description

A set of cpp classes for capturing Project Cars UDP telemetry.

## Contents
* [Introduction](#T-Introduction)
* [Install Binarys](#T-Installation)

## <a name="T-Introduction"></a>Introduction

A set of classes that can be used to roll your own to UDP capture telemetry application.

## <a name="T-Installation"></a>Install Binarys

### Capture Lap Data Demo
Capture lap data creates a lap_data.json file with all the previous laps data.
You can either write your on html file to view the json in a browser or use track_9.html,
however there is only currenlty three race lines recorded zolder, dubai club and oulton park island.
#### OSX
* This is only a local install i.e. download to a directory in your home directory.
* Open a terminal
* cd to src directory. 
  * ```# cd ./src```
* run "make install"
  * ```# make install```
* run "make"
  * ```# make```
* cd capture_lap_data
  * ```# cd ./bin/capture_lap_data```
* run "make"
  * ```# make```
* Export DYLD_LIBRARY_PATH to ./lib
  * ```# export DYLD_LIBRARY_PATH=/home/your_home/your_pcars_dir_path/lib```
* run pcars
  * ```# ./pcars```
