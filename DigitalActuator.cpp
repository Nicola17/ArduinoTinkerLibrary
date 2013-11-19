#include "DigitalActuator.h"

namespace Tinker{
	DigitalActuator::DigitalActuator(int pin): 
		_pin(pin),
		_log(0),
		_enabled(false)
	{}
	
	void DigitalActuator::setPin(int pin){
		if(_log!=0){
			_log->display("Setting on/off actuator pin: "); 	_log->display(_pin); 	_log->endline();
		}
		_pin = pin;
	}
	int DigitalActuator::pin()const{
		return _pin;
	}

	void DigitalActuator::setEnabled(boolean v){
		if(_log!=0){
			if(v){
				_log->display("Actuator: ON"); _log->endline();
			}else{
				_log->display("Actuator: OFF"); _log->endline();
			}
		}
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
		if(_log!=0){
			_log->display("Initializing on/off actuator on pin "); 	_log->display(_pin); 	_log->endline();
		}
      pinMode(_pin, OUTPUT);  
   }	
}
