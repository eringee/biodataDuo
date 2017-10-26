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

void updateLeds() {

  int gsrLight = GSRmastered * 500; //LED still flickers...could be improved
                   
  if(gsrSensorReading<GSRav) gsrLightFinal = 0;       //less than average implies an absence of sweat
  else gsrLightFinal = gsrLight;
  
  analogWrite(gsrLed, gsrLightFinal);
  
  analogWrite(heartLed, heartSensorFiltered * 255);

  
  }


