#include "Vect3d.h"
#include "SerialLog.h"
#include "NeoPixelCircularDisplay.h"
#include <Adafruit_NeoPixel.h>


/***********************************************
 * NeoPixelCircularDisplay - test and example
 ***********************************************/
typedef Tinker::NeoPixelCircularDisplay<> CircularDisplay;
Tinker::SerialLog serialLog;
CircularDisplay circDisplay(8);


void setup(){
	Serial.begin(9600);
	serialLog.display("******************************");
	serialLog.display("NeoPixel circular display test");
	serialLog.display("******************************");
	serialLog.endline();

//        circDisplay._log = &serialLog;
        circDisplay._log = 0;

        circDisplay.init();
        circDisplay.setBrightness(20);
        circDisplay.setColor(CircularDisplay::color_type(0,150,255));
        circDisplay.show();
        delay(1000);
        circDisplay.setColor(CircularDisplay::color_type(255,150,0));
        circDisplay.show();
        delay(1000);
        circDisplay.reset();
        circDisplay.setColor(0,CircularDisplay::color_type(0,255,0));
        circDisplay.setColor(8,CircularDisplay::color_type(0,255,0));
        circDisplay.show();
        delay(1000);  
        circDisplay.setColor(4,CircularDisplay::color_type(255,0,255));
        circDisplay.setColor(12,CircularDisplay::color_type(255,0,255));
        circDisplay.show();
        delay(1000);  
        circDisplay.setColor(0,CircularDisplay::color_type(255,0,255),true);
        circDisplay.setColor(8,CircularDisplay::color_type(255,0,255),true);
        circDisplay.show();
        delay(1000); 
}

const float sigmaMilliSec(CircularDisplay::radBetweenPixels()/6);
const float sigmaSec(CircularDisplay::radBetweenPixels()/3.5);
const float sigmaMin(CircularDisplay::radBetweenPixels()/2);
const float sigmaHour(CircularDisplay::radBetweenPixels()/1.5);

const CircularDisplay::color_type colorMilliSec(200,120,0);
const CircularDisplay::color_type colorSec(0,200,0);
const CircularDisplay::color_type colorMin(0,0,200);
const CircularDisplay::color_type colorHour(200,0,0);

void loop(){
        const unsigned long millxSec(1000);
        const unsigned long millxMin(millxSec*60);
        const unsigned long millxHour(millxMin*60);
        const unsigned long millx12Hour(millxHour*12);
        const unsigned long time = millis();

        const float radMilliSec = 2.*PI*(time%millxSec)/millxSec;
        const float radSec = 2.*PI*(time%millxMin)/millxMin;
        const float radMin = 2.*PI*(time%millxHour)/millxHour;
        const float radHour = 2.*PI*(time%millx12Hour)/millx12Hour;
        
	circDisplay.reset(); 
        circDisplay.setColorFp(radMilliSec,colorMilliSec,sigmaMilliSec,true);
        circDisplay.setColorFp(radSec,colorSec,sigmaSec,true);
        circDisplay.setColorFp(radMin,colorMin,sigmaMin,true);
        circDisplay.setColorFp(radHour,colorHour,sigmaHour,true);

        circDisplay.show();
}
