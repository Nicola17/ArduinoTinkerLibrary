#include "TinkerWatchImpl.h"
#include "ToggleSwitch.h"
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