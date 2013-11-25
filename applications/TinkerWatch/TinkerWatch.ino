#if 0
	#include "ToggleSwitch.h"
	#include "SerialLog.h"
	#include "SequentialStatusSwitcher.h"
	#include "TimedButton.h"

	
#endif

#include "TinkerWatchImpl.h"
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303.h>

TinkerWatchImpl tinkerWatch;

void setup(){
	Serial.begin(9600);
	tinkerWatch.initialize();

}

void loop(){
	tinkerWatch.update();
}