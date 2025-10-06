#include "Arduino.h"

#define Vin 12 //*** Define the GPIO pin 12 as Vin ***
#define Vout 27//*** Define the GPIO pin 27 as Vout ***


float x;
float y;

void setup() {

  Serial.begin(115200); //*** Define the data rate as 115200 ***
  pinMode(Vin , OUTPUT); //*** Set Vin as OUTPUT ***
  pinMode(Vout , INPUT); //*** Set Vout as INPUT ***


  delay(100);   //*** Set 100 ms delay ***
  //This task only needs to be done once, thus it is placed in setup().
  Serial.println(" Duty(%),Vout(V) "); // display duty cycle,Vout for TASK 1 or I,Vout for Task 2 3 4
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) 
    {
    

    
    analogWrite(Vin , (onPeriod));// Output PWM at Vin      
    int Vout_value = analogRead(Vout); // read the voltage level at Vout 
    x = float(onPeriod)*100/255 ; // calculate duty cycle for TASK 1
    y = float(Vout_value*3.3)/4095 ; // convert 12 bit binary number of Vout back to 0-3.3 V 
    Serial.print(x); 
    Serial.print(","); // seperate values by comma 
    Serial.println(y);
  }

  // Press reset button for a new sweep
}

void loop() {
  // Code for continuous operation can be added here
 
}
// git commit -m "Initial commit";