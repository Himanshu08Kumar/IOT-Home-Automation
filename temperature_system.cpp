#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"


void init_temperature_system(void)
{
    //to config heater and cooler pins as output
    pinMode(HEATER, OUTPUT);
    pinMode(COOLER, OUTPUT);
    
    //to turn off the heater and Cooler Pin
    digitalWrite(HEATER, LOW);
    digitalWrite(COOLER, LOW);
    
}

float read_temperature(void)
{
    float temperature;
    // read the analog value and contain the voltage and then convert the temp in degree celsius  
    temperature = (((analogRead(TEMPERATURE_SENSOR)* (float)5/1024)) / (float) 0.01);
    return temperature;
}

//function to control the Cooler

void cooler_control(bool control)
{
   if(control)
   {
      digitalWrite(COOLER, HIGH);     
   }else
   {
      digitalWrite(COOLER, LOW);   
  }
}
void heater_control(bool control)
{
    if(control)
   {
      digitalWrite(HEATER, HIGH);     
   }else
   {
      digitalWrite(HEATER, LOW);   
  }
}
