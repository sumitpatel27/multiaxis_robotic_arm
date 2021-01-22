#include <Wire.h>
#include "Adafruit_TCS34725.h"
 
/* Example code for the Adafruit TCS34725 breakout library */
 
/* Connect SCL to analog 5
Connect SDA to analog 4
Connect VDD to 3.3V DC
Connect GROUND to common ground */
 
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();
 
/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
 
void setup(void) {
Serial.begin(57600);
 
if (tcs.begin()) {
Serial.println("Found sensor");
} else {
Serial.println("No TCS34725 found ... check your connections");
while (1);
}
 
// Now we're ready to get readings!
}
 
void loop(void) {

uint16_t r, g, b, c, colorTemp, lux;
 
tcs.getRawData(&r, &g, &b, &c);
colorTemp = tcs.calculateColorTemperature(r, g, b);
lux = tcs.calculateLux(r, g, b);

 
Serial.print("Color Temp: "); Serial.print(colorTemp); Serial.print(" K - ");
Serial.print("Lux: "); Serial.print(lux); Serial.print(" - ");
Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
Serial.println(" ");

///////////////////FOR COLOR RANGE////////////////////
if (lux>=60000)

 {
  if (r<5000){Serial.print("RED");}
  else{Serial.print("Orange");}
  }

if(400<=lux && lux<=5000)
{

  if(colorTemp>=16000){Serial.print("Blue");}
  else if(1600<colorTemp && colorTemp<=2500){Serial.print("yellow");}
  else{Serial.print("Green");}
  }

else if (300<=lux && lux<400)
{
  if(colorTemp>=6000 && colorTemp<=8000){Serial.print("Purple");}
  else if(10000<=colorTemp){Serial.print("Blue");}
  else if(colorTemp>=3500 && colorTemp<=6000){Serial.print("Green");}
  else{Serial.print("Yellow");}
  }
else if (160<=lux && lux<300)
{
  if(colorTemp<=4000){Serial.print("Purple");}
  else if(10000<=colorTemp){Serial.print("Blue");}
  else{Serial.print("Green");}
  }
else if (lux<160)
{
if(7000<=colorTemp){Serial.print("Blue");}
else {Serial.print("Purple");}
}

Serial.println();















//////////////////////////////////////////////////////
}
