#include <Chrono.h>
#include <Average.h>    // library for averaging data


Average<float> GSRaverager(1250);  //1250
Average<float> GSRlightav(1000);
Average<float> gsrLighter(500);

int gsrSensorReading;
float GSRmastered;   //The final GSR value that you will send to serial
float GSRmax;
float GSRav;
int gsrLightFinal;
int maxat = 0;

int heartLight;
int gsrLight;

int gsrLed   =  4;    
int heartLed =  5; 

Chrono bpmChrono;

float bpm = 70;  // this value is fed to initialize your BPM before a heartbeat is detected

#include "MinMax.h"
MinMax heartMinMax = MinMax();
MinMax gsrMinMax = MinMax();

#include "Threshold.h"
Threshold heartThresh = Threshold(0.25, 0.75);

#include "Lop.h"
Lop gsrLop = Lop(0.001); //0.001

#include "Hip.h"
Hip gsrHip = Hip(0.9999);//Hip(0.9999);
Lop heartSensorAmplitudeLop = Lop(0.001  );
Lop heartSensorBpmLop = Lop(0.001);

float heartSensorAmplitudeLopValue;

float heartSensorBpmLopValue;
MinMax heartSensorAmplitudeLopValueMinMax = MinMax();

float heartSensorAmplitudeLopValueMinMaxValue;
MinMax heartSensorBpmLopValueMinMax = MinMax();

float heartSensorBpmLopValueMinMaxValue;

float heartSensorFiltered = 0;
float heartSensorAmplitude = 0;

float gsrSensorFiltered = 0;
float gsrSensorAmplitude = 0;
float gsrSensorLop = 0;
float gsrSensorChange = 0;

void setup(void)
{
  Serial.begin(115200);

  pinMode(heartLed, OUTPUT);      //led for heart signal
  pinMode(gsrLed, OUTPUT);        // led for gsr

}

elapsedMillis every4;  // this calls the function every 4 milliseconds

void loop() {
  
 processHeart();  //only needs to be 250Hz (4 millis)
 processGsr();    //only needs to be 100Hz (6 millis) take avg over 4 seconds and subtract from signal to eliminate noise
 updateLeds();
 updateSerial();
 
}




