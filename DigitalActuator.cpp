#include "DigitalActuator.h"

namespace Tinker{
	DigitalActuator::DigitalActuator(int pin): 
		_pin(pin),
		_log(0),
		_enabled(false)
	{}
	
	void DigitalActuator::setPin(int pin){
		SECURE_LOG_VAL(_log,"Setting on/off actuator pin", _pin);
		_pin = pin;
	}
	int DigitalActuator::pin()const{
		return _pin;
	}

	void DigitalActuator::setEnabled(boolean v){
		SECURE_LOG_ONOFF(_log,"Actuator")
		_enabled = v;
		if(v)
			digitalWrite(_pin, HIGH);
		else
			digitalWrite(_pin, LOW);
	}
	boolean DigitalActuator::enabled()const{
		return _enabled;
	}

   void DigitalActuator::initialize(){
		SECURE_LOG_VAL(_log,"Initializing on/off actuator on pin",_pin);
		pinMode(_pin, OUTPUT);  
   }	
}
