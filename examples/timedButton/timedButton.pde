#include "ToggleSwitch.h"
#include "SerialLog.h"
#include "DigitalActuator.h"
#include "TimedButton.h"

/*******************************
 * TimedButton - test and example
 *******************************/

Tinker::SerialLog 		serialLog;
Tinker::DigitalActuator led;
Tinker::TimedButton		button;

void setup(){
	Serial.begin(9600);
	serialLog.display("TimedButton Example\n");
	
	led.setPin(13);
	led.initialize();

	button._log = &serialLog;
	button.setPin(2);
	button.initialize(1000,5000); //Setting a minimum of one sec and a maximum of five sec to activate
}

void loop(){
      const boolean activated(button.enabled());
      if(activated){
	  led.setEnabled(true);
          delay(100);
	  led.setEnabled(false);
      }
}