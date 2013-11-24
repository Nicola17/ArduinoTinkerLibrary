#include "TMP36.h"

namespace Tinker{

	TMP36::TMP36(int pin): 
		_pin(pin),
		_log(0),
		_voltageRef(0)
	{}
	
	void TMP36::setPin(int pin){
		_pin = pin;
	}
	int TMP36::pin()const{
		return _pin;
	}

	void TMP36::setVoltageRef(float vRef){
		_voltageRef = vRef;
	}
	float TMP36::voltageRef()const{
		return _voltageRef;
	}

   void TMP36::initialize(){
      pinMode(_pin, INPUT);  
   }	
        
	float TMP36::value(){
		int sensorVal = analogRead(_pin);
		float voltage = (sensorVal/1024.)*_voltageRef;
		float temperature = (voltage*100)-50;
		
		if(_log!=0){
			_log->display("Sensor val: "); 	_log->display(sensorVal); 	_log->endline();
			_log->display("Voltage: "); 		_log->display(voltage); 		_log->endline();
			_log->display("Temperature: "); 	_log->display(temperature); 	_log->endline();
			_log->display("**************************************************"); _log->endline();
		}
		return temperature;
	}
}

