#include "ToggleSwitch.h"
#include "SerialLog.h"
#include "DigitalActuator.h"
#include "TimedButton.h"

/*******************************
 * TimedButton - test and example
 *******************************/

Tinker::SerialLog 		serialLog;
typedef Tinker::SequentialStatusSwitcher<TimedButton>	StatusSwitcher;

StatusSwitcher::status_type currentStatus = 0;
StatusSwitcher statusSwitcher;

void setup(){
	Serial.begin(9600);
	serialLog.display("SequentialStatusSwitcher Example\n");
	
	button._log = &serialLog;
	//statusSwitcher.switch().setPin(2);
	//statusSwitcher.switch().initialize(1000,5000); //Setting a minimum of one sec and a maximum of five sec to activate
}

void loop(){
      const boolean activated(button.enabled());
      if(activated){
	  led.setEnabled(true);
          delay(100);
	  led.setEnabled(false);
      }
}