/******************************************************
copyright Erin Gee 2017

Authors Erin Gee // Martin Peach // Thomas Ouellet-Fredericks

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License version 3 as published by
the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    For more details: <http://www.gnu.org/licenses/>.

******************************************************/

void processHeart() {
   // HEART
  int heartSensorReading = analogRead(A8);

  heartSensorFiltered = heartMinMax.filter(heartSensorReading);
  heartSensorAmplitude = heartMinMax.getMax() - heartMinMax.getMin();
  heartMinMax.adapt(0.01); // APPLY A LOW PASS ADAPTION FILTER TO THE MIN AND MAX

  heartSensorAmplitudeLopValue = heartSensorAmplitudeLop.filter(heartSensorAmplitude); 
  heartSensorBpmLopValue =  heartSensorBpmLop.filter(bpm);

   heartSensorAmplitudeLopValueMinMaxValue = heartSensorAmplitudeLopValueMinMax.filter(heartSensorAmplitudeLopValue);
   heartSensorAmplitudeLopValueMinMax.adapt(0.001);
   heartSensorBpmLopValueMinMaxValue = heartSensorBpmLopValueMinMax.filter(heartSensorBpmLopValue);
  heartSensorBpmLopValueMinMax.adapt(0.001);

  bool beatDetected = heartThresh.detect(heartSensorFiltered);

  if ( beatDetected ) {
    unsigned long temporaryBpm = 60000. / (bpmChrono.elapsed());
    bpmChrono.restart();
    if ( temporaryBpm > 30 && temporaryBpm < 200 ) 
      bpm = temporaryBpm;
  }
}

