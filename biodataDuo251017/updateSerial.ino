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

