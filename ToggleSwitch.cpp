#include "ToggleSwitch.h"

namespace Tinker{

	ToggleSwitch::ToggleSwitch(int pin): 
		_pin(pin),
		_log(0)
	{}
	void ToggleSwitch::setPin(int pin){
		if(_log!=0){
			_log->display("Setting on/off actuator pin: "); 	_log->display(_pin); 	_log->endline();
		}
		_pin = pin;
	}
	int ToggleSwitch::pin()const{
		return _pin;
	}
	boolean ToggleSwitch::enabled()const{
		return (digitalRead(_pin)== HIGH);
	}
   void ToggleSwitch::initialize(){
		if(_log!=0){
			_log->display("Initializing on/off actuator on pin "); 	_log->display(_pin); 	_log->endline();
		}
		pinMode(_pin, INPUT);  
   }	
}
