#include "ToggleSwitch.h"

namespace Tinker{
	void ToggleSwitch::setPin(uint16_t pin){
		_pin = pin;
	}
	int ToggleSwitch::pin()const{
		return _pin;
	}
	boolean ToggleSwitch::enabled()const{
		if(_enabledOnLow)
			return (digitalRead(_pin)== LOW);
		return (digitalRead(_pin)== HIGH);
	}
	boolean ToggleSwitch::enabledOnLow()const{
		return _enabledOnLow;
	}
	boolean ToggleSwitch::pullUpResistor()const{
		return _pullUpResistor;
	}
   void ToggleSwitch::initialize(bool enabledOnLow, bool pullUpResistor){
		SECURE_LOG_VAL(_log,"Initializing toggle switch on pin",_pin);
		_pullUpResistor  = pullUpResistor;
		_enabledOnLow = enabledOnLow;
		
		pinMode(_pin, INPUT);  
		if(_pullUpResistor)
			digitalWrite(_pin, HIGH);
		else
			digitalWrite(_pin, LOW);
   }	
}
