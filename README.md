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
* [Class Structure](#T-classes)
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

## <a name="T-classes"></a>Class Structure
### Transport

```
  8 class Transport {
  9 public:
 10         virtual ~Transport() {};
 11 
 12         virtual PCars_Data read(const Amount) = 0;
 13         virtual void write(const PCars_Data &) = 0;
 14 };
```

Transport is simply the type that reads or writes (interface for write but no impl) to and from a peer. 
Transport_UDP is a Transport Type that reads UDP packets.  
PCars_Data is a std::vector of unsigned chars.

### Decoder

```
  8 class Decoder {
  9 public:
 10         virtual ~Decoder() {}
 11 
 12         virtual void decode(const PCars_Data &, Position &) = 0;
 13 };
```

Decoder is loosely based on the interpreter pattern which decodes specific elements of a packet e.g.

```
  8 class Decoder_F32: public Decoder {
  9 public:
 10         Decoder_F32();
 11         virtual ~Decoder_F32() {}
 12 
 13         void decode(const PCars_Data &, Position &) override;
 14 
 15         float f32() const;
 16 
 17 private:
 18         float num_;
 19 };
``` 

Decoder_F32 is a Decoder that decodes a Float 32bit element such as a "f32   sBestLapTime;"
Position is the position of the current element in the packet and may get incremeneted to the next packet e.g. for f32 we would increment by 4 because 32/8 is 4, however if it was a bit wise operation say MS 3bit it would not increment the value because the next decoder may need the LS 3bit. Anyway this is done under the covers in the Decoder and the Decoder_Composite.

### Decoder_Compiste

```
  8 class Decoder_Composite : public Decoder {
  9 public:
 10         using Vector_Decoder = std::vector<Decoder *>;
 11 
 12         virtual ~Decoder_Composite() {}
 13 
 14         virtual void decode(const PCars_Data &, Position &);
 15 
 16         void add(Decoder *);
 17 
 18 private:
 19         Vector_Decoder decoders_;
 20         Vector_Decoder::iterator iter_;
 21 };

```

Decoder_Composite is a Decoder it is the Composite Pattern and is used to string together Packages, Decoder_Telemetry_Data is Decoder_Composite and is an example of creating a package decoder by adding Decoders.

Decoder Note: I know just copying a package to a struct is QUICK and my decoder is slow in comparison however copying a struct is not as fun as implementing a design pattern :-). 

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
