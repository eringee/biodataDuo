void updateLeds() {

  int gsrLight = GSRmastered * 500; //LED still flickers...could be improved
                   
  if(gsrSensorReading<GSRav) gsrLightFinal = 0;       //less than average implies an absence of sweat
  else gsrLightFinal = gsrLight;
  
  analogWrite(gsrLed, gsrLightFinal);
  
  analogWrite(heartLed, heartSensorFiltered * 255);

  
  }


