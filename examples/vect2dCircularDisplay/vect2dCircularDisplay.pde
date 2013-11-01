#include "Vect3d.h"
#include "Vect2d.h"
#include "SerialLog.h"
#include "NeoPixelCircularDisplay.h"
#include "Vect2dCircularDisplay.h"

#include <Adafruit_NeoPixel.h>


/***********************************************
 * Vect2CircularDisplay - test and example
 ***********************************************/
typedef Tinker::NeoPixelCircularDisplay<> CircularDisplay;
typedef Tinker::Vect2dCircularDisplay<CircularDisplay,6> VectCircularDisplay;

Tinker::SerialLog serialLog;
VectCircularDisplay vectDisplay(2);

void setup(){
  Serial.begin(9600);
  //vectDisplay._log = &serialLog;
  vectDisplay.init(0,10,CircularDisplay::radBetweenPixels(),CircularDisplay::radBetweenPixels()*2,10,40);
  vectDisplay.setColor(0,VectCircularDisplay::color_type(0,0,0));
  vectDisplay.setColor(1,VectCircularDisplay::color_type(0,0,255));
  vectDisplay.setColor(2,VectCircularDisplay::color_type(0,255,255));
  vectDisplay.setColor(3,VectCircularDisplay::color_type(0,255,0));
  vectDisplay.setColor(4,VectCircularDisplay::color_type(255,255,0));
  vectDisplay.setColor(5,VectCircularDisplay::color_type(255,0,0));
}

void loop(){
  int s0 = analogRead(A0);
  int s1 = analogRead(A1);
  float intensity((s0+1)/1025.*10);
  float dir(s1/1024.*2*PI);
  
  Tinker::Vect2d<float> v(cos(dir),sin(dir));
  v *= intensity;
  vectDisplay.show(v);
}