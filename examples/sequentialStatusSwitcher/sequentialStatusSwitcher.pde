#include "ToggleSwitch.h"
#include "SerialLog.h"
#include "SequentialStatusSwitcher.h"
#include "TimedButton.h"

/*******************************
 * TimedButton - test and example
 *******************************/

Tinker::SerialLog 		serialLog;
typedef Tinker::SequentialStatusSwitcher<Tinker::TimedButton>	StatusSwitcher;

StatusSwitcher::status_type nStatus = 5;
StatusSwitcher::status_type currentStatus = 0;
StatusSwitcher statusSwitcher;

void setup(){
	Serial.begin(9600);
	serialLog.display("SequentialStatusSwitcher Example\n");
	
	statusSwitcher._log = &serialLog;
	statusSwitcher.switcher().setPin(2);
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
}