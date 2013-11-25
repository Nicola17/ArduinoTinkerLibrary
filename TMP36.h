#ifndef TMP36_H
#define TMP36_H

#include "AbstractLog.h"
#include "AbstractSensor.h"

namespace Tinker{

	//! A class to handle TMP36 sensor
	/*!
		\author Nicola Pezzotti
	*/
	class TMP36: public AbstractScalarSensor{
	public:
		//! Creates an unitialized TMP36 sensor. 
		TMP36():_log(0),_voltageRef(0){}
		//! Creates an unitialized TMP36 sensor. 
		TMP36(int pin);
		//! Sets sensor pin. 
		void setPin(int pin);
		//! Returns sensor pin. 
		int pin()const;
		//! Sets sensor voltage reference. 
		void setVoltageRef(float vRef);
		//! Returns sensor voltage reference. 
		float voltageRef()const;
		//! Initializes sensor. 
		void initialize();
		//! Return sensor readings.
		virtual float value();
		
	private:
		int _pin;
		float _voltageRef;

	public:
		AbstractLog* _log;
	};
}

#endif
