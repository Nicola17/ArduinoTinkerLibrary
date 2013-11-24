#if 0
	#include "ToggleSwitch.h"
	#include "SerialLog.h"
	#include "SequentialStatusSwitcher.h"
	#include "TimedButton.h"

	/*******************************
	 * Tinker Watch
	 *******************************/

	Tinker::SerialLog 		serialLog;
	typedef Tinker::SequentialStatusSwitcher<Tinker::TimedButton>	StatusSwitcher;

	StatusSwitcher::status_type nStatus = 5;
	StatusSwitcher::status_type currentStatus = 0;

	StatusSwitcher statusSwitcher;

	enum Mode{
		Compass = 0,
		Accellerometer = 1,
		GPS = 2, 
		Clock = 3,
		RandomAnimation = 4
	};

	void setup(){
		Serial.begin(9600);
		serialLog.display("Tinker Watch\n");

	// Status switcher initialization
		statusSwitcher._log = &serialLog;
		statusSwitcher.switcher().setPin(10);
		statusSwitcher.switcher().initialize(1000,5000); //Setting a minimum of one sec and a maximum of five sec to activate
		statusSwitcher.setNumberOfStatus(nStatus);
		statusSwitcher.setStatus(currentStatus);
	}

	void loop(){
		statusSwitcher.refresh();
		StatusSwitcher::status_type s = statusSwitcher.status();
		if(s!=currentStatus){
			SECURE_LOG_VAL(statusSwitcher._log,"New status",s);
			currentStatus = s;
		}
		switch(currentStatus){
			case Compass: break;
			case Accellerometer: break;
			case GPS: break;
			case Clock: break;
			case RandomAnimation: break;
		}
	}
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