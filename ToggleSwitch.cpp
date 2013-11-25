#include "ToggleSwitch.h"

namespace Tinker{

	ToggleSwitch::ToggleSwitch(int pin): 
		_pin(pin),
		_log(0)
	{}
	void ToggleSwitch::setPin(int pin){
		SECURE_LOG_VAL(_log,"Setting toggle switch pin",_pin);
		_pin = pin;
	}
	int ToggleSwitch::pin()const{
		return _pin;
	}
	boolean ToggleSwitch::enabled()const{
		return (digitalRead(_pin)== HIGH);
	}
   void ToggleSwitch::initialize(){
		SECURE_LOG_VAL(_log,"Initializing toggle switch on pin",_pin);
		pinMode(_pin, INPUT);  
   }	
}
