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

void updateSerial() {
  Serial.print(heartSensorFiltered);
  Serial.print("\t");
  
  Serial.print(bpm);
  Serial.print("\t");
  
  Serial.print(heartSensorAmplitudeLopValueMinMaxValue);
  Serial.print("\t");

  Serial.print(heartSensorBpmLopValueMinMaxValue);
  Serial.print("\t");
  
  Serial.println(GSRmastered);
  
}

