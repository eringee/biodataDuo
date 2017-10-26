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

void processGsr() {

  gsrSensorReading = analogRead(A6);    //read the signal
  gsrSensorReading = (gsrSensorReading-1023)*-1;    //inverse the value
  
  gsrSensorLop = gsrLop.filter(gsrSensorReading);
  gsrSensorFiltered = gsrMinMax.filter(gsrSensorLop); // Min max the data
  gsrMinMax.adapt(0.01);   // APPLY A LOW PASS ADAPTION FILTER TO THE MIN AND MAX
  
  if(gsrSensorLop<0) GSRaverager.push(gsrSensorLop-10); //only the greater than average values matter, shove the lesser than values down quick
  else GSRaverager.push(gsrSensorLop);               //array for determining an average GSR over time
  
  GSRav = GSRaverager.mean();        
  GSRmastered = (gsrSensorLop-GSRav) / 10;                    
  if (GSRmastered<0) GSRmastered = 0;
  if(gsrSensorLop>GSRmax) GSRmax = gsrSensorLop;      //keep track of the latest max value 
  else GSRmax = (GSRaverager.maximum(&maxat));

  if (GSRmastered>1.) GSRmastered = 1.;        //keep the mapping below 1 no matter what

}

