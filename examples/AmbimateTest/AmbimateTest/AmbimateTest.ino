#include <Wire.h>
#include <Ambimate.h>


Ambimate amb;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
 
  if ( !amb.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
   Serial.println(amb.opt_sensors);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (amb.Measure()) {
  Serial.print("VOC= ");Serial.println(amb.TVOC);
  Serial.print("eC02= ");Serial.println(amb.eCO2);
  Serial.print("Light= ");Serial.println(amb.LUM);
   Serial.print("VOLTS= ");Serial.println(amb.VOLTS);
  if (amb.EVENT == true){
    Serial.println("EVENT= TRUE");

    }else{
       Serial.println("EVENT= FALSE");
}
    
    }else{
       Serial.println("Measurement Failed");
 
      }
  
  
  delay(1000);
  

}
